#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  int n, x, y, res = 0;
  int axis[301] = {0};
  input >> n;
  for (int i = 0; i < n; i++) {
    input >> x >> y;
      for (int j = 100 + x + 1 - y; j <= (100 + x + y); j++) {
        axis[j] ++;
      }
  }
  for (int i = 100; i <= 199; i++) {
    res = max(res, axis[i]);
  }
  output << res << endl;
}