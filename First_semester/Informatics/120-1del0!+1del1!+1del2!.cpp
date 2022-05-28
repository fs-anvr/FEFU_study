#include <iostream>

using namespace std;

int main() {
  int N; double S, del;
  cin >> N;
  S = 1; del = 1;
  for (int i = 1; i <= N; i++) {
    del = del * i;
    S += 1 / del;
  }
  cout << S << endl;
}