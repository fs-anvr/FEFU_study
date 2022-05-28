#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    float a, b, c, x1, x2, D;
    input >> a >> b >> c;
    if (c == 0) 
    {
        output<<fixed<<setprecision(4)<< 0 << " " << 0;
        return 0;
    }
    else if (a == 0 && b == 0) 
    {
        output << -1;
        return 0;
    }
    else if (a == 0 && b != 0) 
    {
        output<<fixed<<setprecision(4)<< -c / b << " " << -c / b;
        return 0;
    }
    else if (a != 0 && b == 0) 
    {
        if (c < 0)
        {
            output<<fixed<<setprecision(4)<< sqrt(-c / a) << " " << -sqrt( -c / a);
            return 0;
        }
        else 
        {
            output << -1;
            return 0;
        }
    }
    D = b*b - 4*a*c;
    if (D < 0) 
    {
        output << -1;
    }
    else if (D > 0) 
    {
        x1 = (-b + sqrt(D)) / (2*a);
        x2 = (-b - sqrt(D)) / (2*a);
        output <<fixed<<setprecision(4)<< max(x1, x2) << " " << min(x1, x2);
    }
    else if (D == 0) 
    {
        x1 = (-1*b) / (2*a);
        output <<fixed<<setprecision(4)<< x1 << " " << x1;
    }
}