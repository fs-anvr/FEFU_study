#include <iostream>
#include <math.h>

using namespace std;

int main(){
  double a, b, c, d;
  cin >> a; cin >> b; cin >> c;
  d = b*b - 4*a*c;
  if (d > 0) {
    cout << ((-b + sqrt(d))/(2*a)) << " ";
    cout << ((-b - sqrt(d))/(2*a)) << endl;
  }
  else if (d == 0) {
    cout << (-b/(2*a)) << endl;
  }
}