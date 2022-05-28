#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  int n, a, c = 0;
  char t;
  int A[100] = {0};
  input >> n;
  for (int i = 0; i < n; i++)
  {
    input >> a;
    A[i] = a;
  }
  for (int i = 0; i < n; i++)
  {
    input >> t;
    if (t == '+')
    {
      c += A[i];
    }
  }
  output << c;
}