#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  std::ifstream fin ("input.txt");
  std::ofstream fout ("output.txt");
  long long x, k;
  fin >> x >> k;
  x = x >> k; x = x % 2;
  fout << x << endl;
}