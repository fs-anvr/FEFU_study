#include <iostream>

using namespace std;

int main() {
  int h, a, b, k, i;
  k = 0; i = 0;
  cin >> h >> a >> b;
  while (k < h) {
    k += a;
    i ++;
    if (k >= h) break;
    k -= b;
  }
  cout << i << "\n";
}