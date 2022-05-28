#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  int n;
  int fn[31] = {0};
  int f0[31] = {0};
  int f1[31] = {0};
  f1[0] = 1;
  input >> n;
  if (n >= 1)
  output << "0";
  if (n >= 2)
  output << " 1";
  for (int i = 1; i < n - 1; i++)
  {
    for (int j = 0; j < 30; j++)
    {
      fn[j] = f0[j] + f1[j];
    }
    for (int j = 0; j < 30; j++)
    {
      if (fn[j] >= 10)
      {
        fn[j+1] += fn[j] / 10;
        fn[j] = fn[j] % 10;
      }
    }
      for (int j = 0; j < 30; j++)
      {
        f0[j] = f1[j];
      }
      for (int j = 0; j < 30; j++)
      {
        f1[j] = fn[j];
      }
    output << " ";
    for (int k = 27; k >=0; k--)
    {
        if (fn[k+3] != 0 || fn[k+2] != 0 || fn[k+1] != 0 || fn[k] != 0)
        {
          output << fn[k];
        }
      }
  }
}