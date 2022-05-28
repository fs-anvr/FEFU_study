#include <iostream>
#include <string>

using namespace std;

int main() {
  string a, b; int c;
  cin >> a >> b;
  c = 0;
  for (int i = 0; i < a.length(); i++) {
    if (a[i] != b[i]) {
      c++;
    }
  } 
  cout << (c) << endl;
}