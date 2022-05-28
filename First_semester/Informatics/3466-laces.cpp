#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int a, b, l, N;
  cin >> a >> b >> l >> N;
  cout << ((N - 1) * 2 + 1) * a + b * (N-1) * 2 + l * 2 << endl;
}