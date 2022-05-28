#include <iostream>

using namespace std;

int main(){
  int n, h, m, s;
  cin >> n;
  s = n % 60;
  m = (n / 60) % 60;
  h = (n / 3600) % 24;
  cout << h << ":" << (m / 10) << (m % 10) << ":" << (s / 10) << (s % 10) << endl;
}