#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;
int main()
{
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  double x1 , x2 , y1 , y2, x, y;
  input >> x1 >> y1 >> x2 >> y2;
  double a = 0, t = 0, f;
  bool out_res = false;
  f = sqrt(pow((x2-x1), 2) + pow((y2-y1), 2));
  if ((abs(x2-x1) != abs(y2-y1)) && f >= 2)
  {
  for (int i = 1; i < 9 && (out_res == false); i++)
  {
    for (int j = 1; j < 9 && (out_res == false); j++)
    {
      if ((abs(i-x1) == abs(j-y1)) && (abs(i-x2) == abs(j-y2)) && (abs(i -x1) != 0) && (abs(i - x2) != 0))
      {
        output << i << " " << j;
        out_res = true;
      } 
    }
  }
  if (out_res == false)
  {
    output << 0;
    out_res = true;
    return 0;
  }
  }
  else  if (f >= 2)
  {
    if (abs(x1 + (x2-x1)/2.0) >= 1 && abs(y1 + (y2-y1)/2.0) >= 1)
    {
    output << (x1 + int(x2-x1)/2) << " " << (y1 + int(y2-y1)/2);
    out_res = true;
    return 0;
    }
    else
    {
      output << 0;
      out_res = true;
      return 0;
    }
  }
  else
  {
    output << 0;
    out_res = true;
    return 0;
  }
  if (out_res == false)
  {
    output << 0;
  }
}