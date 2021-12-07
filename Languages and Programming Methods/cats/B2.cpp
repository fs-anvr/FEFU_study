#include <iostream>
#include <fstream>
using namespace std;

int main() {
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  int f0[101] = {0};
  int f1[101] = {0};
  int fdel[101] = {0};
  f0[0] = 0; f1[0] = 1;
  int n0, k0, del;
  input >> n0 >> k0;
  while ((n0 != 0) && (k0 != 0)) {
    if (n0 > k0)
      n0 = n0 % k0;
    else
      k0 = k0 % n0;
  }
  del = n0 + k0;
  if (del > 1){
  for (int i = 0; i < del -1; i++){
    for (int j = 0; j < 100; j++) {
      fdel[j] = f0[j] + f1[j];
    }
    for (int j = 0; j < 100; j++) {
      if (fdel[j] >= 10) {
        fdel[j+1] += fdel[j] / 10;
        fdel[j] = fdel[j] % 10;
      }
    }
      for (int g = 0; g < 100; g++) {
        f0[g] = f1[g];
      }
      for (int g = 0; g < 100; g++) {
        f1[g] = fdel[g];
      }
    }
    for (int i = 96; i >= 0; i--) {
    if (fdel[i+3] != 0 || fdel[i+2] != 0 || fdel[i+1] != 0 || fdel[i] != 0) {
      output << fdel[i];
    }
  }
  }
  else {
    output << 1;
  }
}
