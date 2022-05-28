#include <iostream>
#include <fstream>

using namespace std;

int main()
{
  ifstream input("input.txt");
  ofstream output ("output.txt");
  int n, a; input >> n;
  int c = 0;
  for (int i = 0; i < n; i++) {
    input >> a;
    c += a;
  }
  output << c << endl;
}