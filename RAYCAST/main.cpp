#include <windows.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <any>

using namespace std;

const short ScreenWidth = 150;
const short ScreenHeight = 40;
const double PI = 3.14159265359;


class CoordinateSystem
{
public:
    double UnitLength;
    CoordinateSystem(double UnitLength)
    {
        this->UnitLength = UnitLength;
    }
    CoordinateSystem()
    {
        this->UnitLength = 1;
    }
};


class Point {

public:
    double x, y, z;

    Point(double X, double Y, double Z)
    {
        x = X;
        y = Y;
        z = Z;
    }
    Point() = default;

    Point operator *(double C)
    {
        return Point(x*C, y*C, z*C);
    }

    Point operator /(double C)
    {
        return *this * (1/C);
    }

    Point operator +(Point other)
    {
        return Point(x + other.x, y + other.y, z + other.z);
    }

    Point operator -(Point other)
    {
        return *this + (other * (-1));
    }

    double distance (Point other)
    {
        return sqrt((x - other.x)*(x - other.x) + (y - other.y)*(y - other.y) + (z - other.z)*(z - other.z));
    }
};


class Angle : public Point
{
public:
    Angle(double a, double b, double g):Point(a,b,g){}
    Angle() = default;
};


class Vector : public Point
{
public:

    Vector(double X, double Y, double Z) : Point(X, Y, Z) {}

    Vector() = default;

    double Length()
    {
        return sqrt(*this * *this);
    }

    double operator *(Vector other)
    {
        return (x * other.x + y * other.y + z * other.z);
    }

    Vector operator *(double C)
    {
        return Vector(x*C, y*C, z*C);
    }

    Vector operator /(double C)
    {
        return *this * (1/C);
    }

    Vector operator +(Point other)
    {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    Vector operator -(Point other)
    {
        return *this + (other * (-1));
    }

    Vector operator ^(Vector other)
    {
        return Vector(this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x);
    }

    double CosAngleBetweenVectors(Vector other)
    {
        return (*this * other) / (this->Length() * other.Length());
    }

    void Normalize()
    {
        double length = sqrt(x * x + y * y + z * z);
        x /= length;
        y /= length;
        z /= length;
    }

    void RotateXY(Angle angle)
    {
        double X = x, Y = y, Z = z;
        x = (X * cos(angle.x) - Y * sin(angle.x)) * cos(angle.x) - Z * sin(angle.x);
        y = X * sin(angle.x) + Y * cos(angle.x);
        z = (X * cos(angle.x) - Y * sin(angle.x)) * sin(angle.x) + Z * cos(angle.x);
    }

    void RotateX(Angle angle) {
        double X = x;
        x = X * cos(angle.x) - y * sin(angle.x);
        y = X * sin(angle.x) + y * cos(angle.x);
    }

    Vector Projection(Vector other)
    {
        Vector result = other;
        double proj = (*this * other) / this->Length();
        //result = result * proj;
        return result * proj;
    }
};


class Camera
{
public:
    Point Position;
    Vector LookAt;
    Vector FOV;
    double DrawDistance;
    int SplitCount;

    Camera(double posX, double posY, double posZ, double rotX, double rotY, double rotZ, double fovX, double fovY, double fovZ, double drawdistance)
    {
        Position = Point(posX, posY, posZ);
        LookAt = Vector(rotX, rotY, rotZ);
        LookAt.Normalize();
        FOV.x = fovX;
        FOV.y = fovY;
        FOV.z = fovZ;
        DrawDistance = drawdistance;
    }
    Camera(Point position, Vector rotation, Vector fov, double drawdistance)
    {
        Position = position;
        LookAt = rotation;
        FOV = fov;
        DrawDistance = drawdistance;
    }
    Camera() = default;
};


class Person
{
public:
    Camera *camera;
    Point *Position;
    Vector *LookAt;
    double R;

    Person(Camera *cam, double r)
    {
        this->camera = cam;
        this->Position = &cam->Position;
        this->LookAt = &cam->LookAt;
        R = r; // радиус хитбокса персонажа. на данном этапе персонаж - цилиндр
    }
    Person() = default;

    void move()
    {
        //move
    }
};


class Ray
{
public:
    Point Position;
    Vector Direction;

    Ray(Camera camera, Angle angle)
    {
        Position = camera.Position;
        Direction = camera.LookAt;
        Direction.RotateXY(angle);
    }
};


class Parameters
{
public:
    double A, B, C;
    virtual double Rotation (Angle angle) = 0;
};


class Object
{
public:
    Point Position;
    //Vector Rotation;

    //virtual bool contains (Point point) = 0;

    virtual double IntersectionDistance(Ray ray) = 0;
    virtual double DistanceToObject(Point point) = 0;
    virtual double Projection(Vector other) = 0;
};


class Plane : public Object
{
public:
    double D;
    Vector Normal;

    Point Bottom;
    Point Top;

    Plane(Point position, double a, double b, double c, Point bottom, Point top)
    {
        Position = { a, b, c };
        D = -(a * position.x + b * position.y + c * position.z);
        Normal = { a, b, c };
        Normal.Normalize();
        Bottom = bottom;
        Top = top;
    }
    double IntersectionDistance(Ray ray)
    {
        if (ray.Direction * Normal)
        {
            double Distance = -(D + ray.Position.x * Position.x + ray.Position.y * Position.y + ray.Position.z * Position.z)
                              / (ray.Direction.x * Position.x + ray.Direction.y * Position.y + ray.Direction.z * Position.z);
            Vector buff = ray.Direction;
            buff = (buff * Distance);
            Point intersect(ray.Position.x + buff.x, ray.Position.y + buff.y, ray.Position.z + buff.z);
            if (intersect.x > Bottom.x && intersect.y > Bottom.y && intersect.z > Bottom.z &&
                intersect.x < Top.x && intersect.y < Top.y && intersect.z < Top.z)
                return Distance;
        }
        return -1;
    }
    double DistanceToObject(Point point)
    {
        Vector norm = Normal;
        double d = norm.Length();
        norm.Normalize();
        return abs(norm.x * point.x + norm.y * point.y + norm.z * point.z - d);
    }
    double Projection(Vector other)
    {
        Vector norm = Normal;
        //norm.multiply(-1);
        double proj = (norm * other) / norm.Length();
        return proj;
    }
};


class Sphere : public Object
{
public:
    double R;
    // Ax^2 + By^2 + Cz^2 = r^2

    Sphere(double X, double Y, double Z, double r)
    {
        Position = { X, Y, Z };
        R = r;
    }
    double IntersectionDistance(Ray ray)
    {
        ray.Direction.Normalize();
        double a = ray.Direction * ray.Direction;
        double b = 2 * (ray.Direction.x * (ray.Position.x - this->Position.x) + ray.Direction.y * (ray.Position.y - this->Position.y) + ray.Direction.z * (ray.Position.z - this->Position.z));
        double c = (ray.Position.x - this->Position.x) * (ray.Position.x - this->Position.x) + (ray.Position.y - this->Position.y) * (ray.Position.y - this->Position.y) + (ray.Position.z - this->Position.z) * (ray.Position.z - this->Position.z) - R * R;
        double discrim = b * b - 4 * a * c;
        if (discrim < 0)
            return -1;
        else if (discrim == 0)
            return (-b / 2 * a);
        else
        {
            double d1 = (-b - sqrt(discrim)) / (2 * a);
            double d2 = (-b + sqrt(discrim)) / (2 * a);
            if (d1 < d2 && d1 > 0)
                return d1;
            else
                return d2;
        }
    }
    double DistanceToObject(Point point)
    {
        return sqrt((Position.x - point.x) * (Position.x - point.x) + (Position.y - point.y) * (Position.y - point.y) + (Position.z - point.z) * (Position.z - point.z));
    }
    double Projection(Vector other)
    {
        return 0;
    }
};


class Canvas
{
public:
    short Width, Height;
    vector <Object*> Map;
    CoordinateSystem Coordinate;
    Canvas(string str, double Unit)
    {
        Width = ScreenWidth;
        Height = ScreenHeight;
        Coordinate.UnitLength = Unit;
    }
    Canvas() = default;
    void append(Object* obj)
    {
        Map.push_back(obj);
    }
    virtual void draw(Camera camera) = 0;
};


class Console : public Canvas
{
public:
    char* Screen = new char [ScreenWidth * ScreenHeight + 1]{'0'};
    string Color;

    Console(string Color):Canvas()
    {
        this->Color = Color;
    }
    void draw(Camera camera)
    {
        for (int X = -ScreenWidth / 2; X < ScreenWidth / 2; X++)
            for (int Y = -ScreenHeight / 2; Y < ScreenHeight / 2; Y++)
            {
                Angle angle((camera.FOV.x / ScreenWidth) * X, (camera.FOV.y / ScreenHeight) * Y, 0);
                Ray ray(camera, angle);
                ray.Direction.Normalize();
                double MinDistance = camera.DrawDistance;
                for (auto it = Map.begin(); it != Map.end(); it++)
                    if ((*it)->IntersectionDistance(ray) > 0 && (*it)->IntersectionDistance(ray) * camera.LookAt.CosAngleBetweenVectors(ray.Direction) <= camera.DrawDistance)
                    {
                        MinDistance = MinDistance < (*it)->IntersectionDistance(ray) ? MinDistance : (*it)->IntersectionDistance(ray) * camera.LookAt.CosAngleBetweenVectors(ray.Direction);
                    }
                char current = Color[(int)(MinDistance * (Color.size() - 1) / camera.DrawDistance)];
                Screen[(ScreenHeight / 2 + Y) * ScreenWidth + (ScreenWidth / 2 + X)] = current;
            }
        std::system("cls");
        std::printf(Screen);
    }
};


int main() {
    Camera MainCamera (Point(0,0,0), Vector(1,0.2,0), Vector (PI/2, PI/3, 0), 100);
    Console console("@Q$0XOUZYCxuzn;:,^'. ");
    Plane Plane1(Point(70, 0, 0), 1, 0, 0, Point(-80, -80, -20), Point(80, 80, 40));
    Plane Plane2(Point(0, 70, 0), 0, 1, 0, Point(-80, -80, -20), Point(80, 80, 40));
    Plane Plane3(Point(-70, 0, 0), 1, 0, 0, Point(-80, -80, -20), Point(80, 80, 40));
    Plane Plane4(Point(0, -70, 0), 0, 1, 0, Point(-80, -80, -20), Point(80, 80, 40));
    console.append(&Plane1);
    console.append(&Plane2);
    console.append(&Plane3);
    console.append(&Plane4);

    console.draw(MainCamera);
    
    getchar();
    return 0;
}
