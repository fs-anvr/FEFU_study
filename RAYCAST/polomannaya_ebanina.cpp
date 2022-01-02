#include <iostream>
#include <math.h>
#include <windows.h>
#include <conio.h>
#include <vector>
using namespace std;


const short ScreenWidth = 150;
const short ScreenHeight = 40;
const double PI = 3.14159265359;




class CoordinateSystem
{
public:
	double UnitVectorLength = 1;
};


class Angle
{
public:
	double alpha, beta, gamma;

	Angle (double a, double b, double g)
	{
		alpha = a;
		beta = b;
		gamma = g;
	}
};


class Point3d {

public:

	Point3d (double X, double Y, double Z)
	{
		x = X;
		y = Y;
		z = Z;
	}

	Point3d() = default;

	Point3d multiply (double C)
	{
		x *= C;
		y *= C;
		z *= C;
		return Point3d(x, y, z);
	}

	Point3d divide (double C)
	{
		return this->multiply(1/C);
	}

	Point3d addition (Point3d other)
	{
		x += other.x;
		y += other.y;
		z += other.z;
		return Point3d(x, y, z);
	}

	Point3d subtract (Point3d other)
	{
		return this->addition(other.multiply(-1));
	}

	double x, y, z;
};


class Vector3d : public Point3d
{
public:

	Vector3d (double X, double Y, double Z) : Point3d (X, Y, Z){}

	Vector3d() = default;


	double multiply_scalar (Vector3d other)
	{
		return (x * other.x + y * other.y + z * other.z);
	}
	double Length()
	{
		return sqrt(this->multiply_scalar(*this));
	}
	double CosAngleBetweenVectors (Vector3d other)
	{
		return (this->multiply_scalar(other)) / (this->Length() * other.Length());
	}
	Vector3d multiply_vector (Vector3d other)
	{
		double X, Y, Z;
		X = this->y * other.z - this->z * other.y;
		Y = this->z * other.x - this->x * other.z;
		Z = this->x * other.y - this->y * other.x;
		return Vector3d (X, Y, Z);
	}
	void Normalize ()
	{
		double length = sqrt(x * x + y * y + z * z);
		x /= length;
		y /= length;
		z /= length;
	}
	void RotateXY(Angle angle)
	{
		double X = x, Y = y, Z = z;
		x = (X * cos(angle.alpha) - Y * sin(angle.alpha)) * cos(angle.beta) - Z * sin(angle.beta);
		y = X * sin(angle.alpha) + Y * cos(angle.alpha);
		z = (X * cos(angle.alpha) - Y * sin(angle.alpha)) * sin(angle.beta) + Z * cos(angle.beta);
	}
	void RotateX(Angle angle) {
		double X = x;
		x = X * cos(angle.alpha) - y * sin(angle.alpha);
		y = X * sin(angle.alpha) + y * cos(angle.alpha);
	}
	Vector3d Projection(Vector3d other)
	{
		Vector3d result = other;
		double proj = this->multiply_scalar(other) / this->Length();
		result.multiply(proj);
		return result;
	}
};


class Camera
{
public:

	Camera (double posX, double posY, double posZ, double rotX, double rotY, double rotZ, double fovX, double fovY, double fovZ, double drawdistance)
	{
		Position = Point3d ( posX, posY, posZ );
		Rotation = Vector3d ( rotX, rotY, rotZ );
		Rotation.Normalize();
		FOV.x = fovX;
		FOV.y = fovY;
		FOV.z = fovZ;
		DrawDistance = drawdistance;
	}
	Camera (Point3d position, Vector3d rotation, Vector3d fov, double drawdistance)
	{
		Position = position;
		Rotation = rotation;
		FOV = fov;
		DrawDistance = drawdistance;
	}
	Camera() = default;

	Point3d Position;
	Vector3d Rotation;

	Vector3d FOV;
	double DrawDistance;
};


class Person : public Camera 
{
public:
	double R;

	Person (Camera camera, double r) : Camera(camera.Position, camera.Rotation, camera.FOV, camera.DrawDistance)
	{
		R = r; // радиус хитбокса персонажа. на данном этапе персонаж - цилиндр
	}
	Person() = default;

	void move ()
	{
		//move
	}
};


class Ray
{
public:
	Point3d Position;
	Vector3d Rotation;

	Ray(Camera camera, Angle angle)
	{
		Position = camera.Position;
		Rotation = camera.Rotation;
		Rotation.RotateXY(angle);
	}

};


class Object
{
public:

	Point3d Position;
	virtual double IntersectionDistance(Ray ray) = 0;
	virtual double DistanceToObject(Point3d point) = 0;
	virtual double Projection(Vector3d other) = 0;
};


class Plane : public Object
{
public:
	double D;
	Vector3d Normal;

	Point3d Bottom;
	Point3d Top;

	Plane (Point3d position, double a, double b, double c, Point3d bottom, Point3d top)
	{
		Position = {a, b, c};
		D = -(a * position.x + b * position.y + c * position.z);
		Normal = { a, b, c };
		Normal.Normalize();
		Bottom = bottom;
		Top = top;
	}
	double IntersectionDistance(Ray ray)
	{
		if (ray.Rotation.multiply_scalar(Normal))
		{
			double Distance = -(D + ray.Position.x * Position.x + ray.Position.y * Position.y + ray.Position.z * Position.z)
				/ (ray.Rotation.x * Position.x + ray.Rotation.y * Position.y + ray.Rotation.z * Position.z);
			Vector3d buff = ray.Rotation;
			buff.multiply(Distance);
			Point3d intersect(ray.Position.x + buff.x, ray.Position.y + buff.y, ray.Position.z + buff.z);
			if (intersect.x > Bottom.x && intersect.y > Bottom.y && intersect.z > Bottom.z &&
				intersect.x < Top.x && intersect.y < Top.y && intersect.z < Top.z)
				return Distance;
		}
		return -1;
	}
	double DistanceToObject (Point3d point)
	{
		Vector3d norm = Normal;
		double d = norm.Length();
		norm.Normalize();
		return abs(norm.x * point.x + norm.y * point.y + norm.z * point.z - d);
	}
	double Projection(Vector3d other)
	{
		Vector3d norm = Normal;
		//norm.multiply(-1);
		double proj = norm.multiply_scalar(other) / norm.Length();
		return proj;
	}
};


class Sphere : public Object
{
public:
	double R;
	// Ax^2 + By^2 + Cz^2 = r^2

	Sphere (double X, double Y, double Z, double r)
	{
		Position = { X, Y, Z };
		R = r;
	}
	double IntersectionDistance(Ray ray) 
	{
		ray.Rotation.Normalize();
		double a = ray.Rotation.multiply_scalar(ray.Rotation);
		double b = 2 * (ray.Rotation.x * (ray.Position.x - this->Position.x) + ray.Rotation.y * (ray.Position.y - this->Position.y) + ray.Rotation.z * (ray.Position.z - this->Position.z));
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
	double DistanceToObject(Point3d point) 
	{
		return sqrt((Position.x - point.x) * (Position.x - point.x) + (Position.y - point.y) * (Position.y - point.y) + (Position.z - point.z) * (Position.z - point.z));
	}
	double Projection(Vector3d other)
	{
		return 0;
	}
};

class Canvas 
{
public:
	short Width, Height;
	char* Screen = new char[ScreenWidth * ScreenHeight + 1];
	string Color;
	Canvas (string str)
	{
		Width = ScreenWidth;
		Height = ScreenHeight;
		for (int i = 0; i < ScreenHeight * ScreenWidth; i++)
		{
			Screen[i] = ' ';
		}
		Screen[ScreenWidth * ScreenHeight] = '\0';
		Color = str;
	}
	Canvas() = default;
};


static class Event
{
public:
	static string send()
	{
		return "onUpdateScreen";
	}
	static void receive()
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 13:
				//Redraw(FirstPlayer, Map, Screen, Color);
				break;
			case 27:
				//run = false;
				break;
			case 119: // W
				//flag = 1;
				//onClickButtonW(&FirstPlayer, Map, 2);
				break;
			case 115: // S
				//flag = 1;
				//onClickButtonS(&FirstPlayer, Map, 2);
				break;
			case 54:
				//flag = 1;
				//onClickButton4(&FirstPlayer);
				break;
			case 52:
				//flag = 1;
				//onClickButton6(&FirstPlayer);
				break;
			default:
				break;
			}
		}
	}
};

class Parameters
{
public:
	Person* Player;
	vector <Object*> Map;
	Canvas canvas;
	Parameters(Person* per, vector <Object*> m, Canvas canv)
	{
		Player = per;
		Map = m;
		canvas = canv;
	}
	Parameters() = default;
};

class MoveParams : public Parameters
{
public:
	double speed;
	MoveParams(Person* per, vector <Object*> m, Canvas canv, double s) : Parameters(per, m, canv)
	{
		speed = s;
	}
	MoveParams() = default;
};

void onClickButtonW (Person* Player, vector <Object*> Map, double speed)
{
	Vector3d add = (*Player).Rotation;
	add.Normalize();
	add.multiply(speed);
	bool flag = 1;
	for (auto it = Map.begin(); it != Map.end() && flag; it++)
	{
		if ((*it)->DistanceToObject((*Player).Position) - (*Player).R < abs((*it)->Projection(add)))
		{
			Vector3d rot((*it)->Position.x, (*it)->Position.y, (*it)->Position.z);
			rot.Normalize();
			rot.multiply(add.Length());
			add.subtract(rot);
			//flag = 0;
		}
	}
	(*Player).Position.addition(add);
}

void onClickButtonS (Person* Player, vector <Object*> Map, double speed)
{
	Vector3d add = (*Player).Rotation;
	add.multiply(speed);
	add.multiply(-1);
	bool flag = 1;
	for (auto it = Map.begin(); it != Map.end() && flag; it++)
	{
		if ((*it)->DistanceToObject((*Player).Position) - (*Player).R < abs((*it)->Projection(add)))
		{
			Vector3d rot((*it)->Position.x, (*it)->Position.y, (*it)->Position.z);
			rot.Normalize();
			rot.multiply(add.Length());
			add.subtract(rot);
			//flag = 0;
		}
	}
	(*Player).Position.addition(add);
}

void onClickButton4 (Person* Player)
{
	(*Player).Rotation.RotateX(Angle(PI / 36, 0, 0));
}

void onClickButton6(Person* Player)
{
	(*Player).Rotation.RotateX(Angle(-PI / 36, 0, 0));
}


void Redraw (Parameters* p)//(Person Player, vector <Object*> Map, Canvas Screen)
{
	//char* Screen = new char[ScreenWidth * ScreenHeight + 1]{ ' ' };
	//Screen[ScreenWidth * ScreenHeight] = '\0';
	auto *par = (MoveParams*) p;
	for (int X = -par->canvas.Width / 2; X < par->canvas.Width / 2; X++)
		for (int Y = -par->canvas.Height / 2; Y < par->canvas.Height / 2; Y++)
		{
			Angle angle((par->Player->FOV.x / par->canvas.Width) * X, (par->Player->FOV.y / par->canvas.Height) * Y, 0);
			Ray ray(*par->Player, angle);
			ray.Rotation.Normalize();
			double MinDistance = par->Player->DrawDistance;
			for (auto it = par->Map.begin(); it != par->Map.end(); it++)
				if ((*it)->IntersectionDistance(ray) > 0 && (*it)->IntersectionDistance(ray) * par->Player->Rotation.CosAngleBetweenVectors(ray.Rotation) <= par->Player->DrawDistance)
				{
					MinDistance = MinDistance < (*it)->IntersectionDistance(ray) ? MinDistance : (*it)->IntersectionDistance(ray) * par->Player->Rotation.CosAngleBetweenVectors(ray.Rotation);
				}
			char current = par->canvas.Color[MinDistance * (par->canvas.Color.size() - 1) / par->Player->DrawDistance];
			par->canvas.Screen[(par->canvas.Height / 2 + Y) * par->canvas.Width + (par->canvas.Width / 2 + X)] = current;
		}
	//std::system("cls");
	std::printf(par->canvas.Screen);
}







static class Receiver
{
public:
	static void CheckButton(Parameters* p)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 13:
				Receiver::receive("ButtonEscape", Redraw, (Parameters*)&p);
				break;
			case 27:
				//run = false;
				break;
			case 119: // W
				//onClickButtonW(Player, Map, 2);
				break;
			case 115: // S
				//onClickButtonS(Player, Map, 2);
				break;
			case 54:
				//onClickButton4(Player);
				break;
			case 52:
				//onClickButton6(Player);
				break;
			default:
				break;
			}
		}
	}


	static void receive(string NameEvent, void (*func)(Parameters*), Parameters *p)
	{
			func(p);
	}
};
void function (Parameters *p)
{
	auto *par = (MoveParams*) p;
	cout << par->Player->FOV.y << "\n";
}




int main()
{
	Camera MainCamera (Point3d(-30, 0, 0), Vector3d(1, 0, 0), Vector3d(PI/2, PI/3, 0), 150);
	Person FirstPlayer(MainCamera, 0.5);

	Plane Plane1 (Point3d(70, 0, 0), 1, 0, 0, Point3d(-80, -80, -20), Point3d(80, 80, 40));
	Plane Plane2 (Point3d(0, 70, 0), 0, 1, 0, Point3d(-80, -80, -20), Point3d(80, 80, 40));
	Plane Plane3 (Point3d(-70, 0, 0), 1, 0, 0, Point3d(-80, -80, -20), Point3d(80, 80, 40));
	Plane Plane4 (Point3d(0, -70, 0), 0, 1, 0, Point3d(-80, -80, -20), Point3d(80, 80, 40));
	Plane Plane5 (Point3d(0, 0, 23), 0, 0, 1, Point3d(-80, -80, -200), Point3d(80, 80, 200));
	Sphere SphereFirst (-10, 5, 0, 5);


	vector <Object*> Map;
	Map.push_back(&Plane1);
	Map.push_back(&Plane2);
	Map.push_back(&Plane3);
	Map.push_back(&Plane4);
	//Map.push_back(&Plane5);
	//Map.push_back(&SphereFirst);



	Canvas Screen("@Q$0XOUZYCxuzn;:,^'. ");
	//string Color = "@Q$0XOUZYCxuzn;:,^'. ";

	//char* Scr = new char[ScreenWidth * ScreenHeight + 1]{' '};
	//Scr[ScreenWidth * ScreenHeight] = '\0';
	//printf(Scr);


	bool run = true;

	while (run)
	{
		//Receiver::receive(&FirstPlayer, Map, Screen, Color);
		MoveParams p ( &FirstPlayer, Map, Screen, 2.0 );
		//Receiver::receive("grebanaya laba", function, (Parameters*) &p);
		Receiver::CheckButton((Parameters*)&p);
		//bool flag = 0;
		/*if (_kbhit())
		{
			switch (_getch())
			{
			case 13:
				Redraw(FirstPlayer, Map, Screen, Color);
				break;
			case 27:
				run = false;
					break;
			case 119: // W
				flag = 1;
				onClickButtonW(&FirstPlayer, Map, 2);
				break;
			case 115: // S
				flag = 1;
				onClickButtonS(&FirstPlayer, Map, 2);
				break;
			case 54:
				flag = 1;
				onClickButton4(&FirstPlayer);
				break;
			case 52:
				flag = 1;
				onClickButton6(&FirstPlayer);
				break;
			default:
				break;
			}
		}
		if (flag)
			Redraw(FirstPlayer, Map, Screen, Color);*/

	}

	//int t = _getch();
	//cout << t;
	return 0;
}
