#include <iostream>

using namespace std;

int main() {
  int a, i;
  cin >> a >> i;
  a = a >> i;
  cout << (a % 2) << endl;
}