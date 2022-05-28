#include <iostream>
#include <fstream>
#include <math.h>
#include <algorithm>
using namespace std;

int main()
{
    double x1, x2, y1, y2;
    double x, y, centX, centY, r1, r2, r3, r4, r, c;
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    input >> x1 >> y1 >> x2 >> y2 >> x >> y;
    centX = (x2 + x1) / 2;
    centY = (y2 + y1) / 2;
    c = sqrt(pow(((x - centX) / 2), 2) + pow(((y - centY) / 2), 2));
    r1 = sqrt(pow(((x - x1) / 2), 2) + pow(((y - y1) / 2), 2));
    r2 = sqrt(pow(((x - x2) / 2), 2) + pow(((y - y2) / 2), 2));
    r3 = sqrt(pow(((x - x1) / 2), 2) + pow(((y - y2) / 2), 2));
    r4 = sqrt(pow(((x - x2) / 2), 2) + pow(((y - y1) / 2), 2));
    r = min (min(r1, r2), min(r3, r4));
    if (r < c)
    {
        output << "CORNER" << endl;
    }
    else
    {
        output << "CENTER" << endl;
    }
  }