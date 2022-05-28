#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  int c, m, n;
  fin >> c >> m;
  n = 1440 - (c*60 + m);
  c = n / 60; m = n % 60;
  fout << c << endl << m << endl;
}