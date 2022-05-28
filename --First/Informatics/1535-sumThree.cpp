#include <iostream>

using namespace std;

int main() {
  int n, c, u = 0;
  cin >> n;
  for (int a = 1; a <= (n / 3) + 1 ; a++) {
    for (int b = a; b <= (n - a) / 2; b++) {
      c = n - a - b;
        if ((b <= c) && (a + b + c) == n) {
          u ++;
        }
    }
  }
  cout << u << endl;
}