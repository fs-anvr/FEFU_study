#include <iostream>
#include <math.h>

using namespace std;

int main() {
  int A, i;
  cin >> A >> i ;
  cout << (A & ~(static_cast<int>(pow(2, i)))) << "\n";
}