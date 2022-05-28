#include <iostream>
#include <fstream>

int main()
{
  int a, b, c;
  std::ifstream fin ("input.txt");
  std::ofstream fout ("output.txt");
  fin >> a >> b >> c;
  a = ((((a >> 2) << 4) ^ b) << 1) | c;
  fout << a << std::endl;
  }