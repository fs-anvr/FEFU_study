#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  int a, b, a0, b0, nok;
  input >> a >> b;
  a0 = a; b0 = b;
  while ((a0 != 0) && (b0 != 0))
  {
    if (a0 > b0)
      a0 = a0 % b0;
    else
      b0 = b0 % a0;
  }
  output << (a0+b0) << " ";
  output << (a*b) / (a0+b0);
}