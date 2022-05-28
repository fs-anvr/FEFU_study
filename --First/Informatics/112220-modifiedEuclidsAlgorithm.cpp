#include <iostream>

using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  int c = 0;
  while ((a != 0) && (b != 0)) {
    if (a > b)
      a = a % b;
    else
      b = b % a;
    c++;
  }
  cout << (a + b) << " " << c << endl;
}