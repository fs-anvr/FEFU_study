#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
  double n, m, k, res, l;
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  fin >> n >> m >> k >> l;
  res = 0; l = l*60.;
  while (l >= m) {
    l -= m + k;
    res += n;
  }
  if (l > 0) {
    res += (n/m)*l;
  }
  fout << int(res) << endl;
}