#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
  int n, i; double a, c;
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  fin >> n;
  for   (i = 0; i < n; i++) {
    fin >> c;
    a += c;
  }
  fout << setprecision(10) << (a / i) << endl;
}