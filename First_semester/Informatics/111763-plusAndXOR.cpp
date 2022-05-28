#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream fin ("input.txt");
  ofstream fout ("output.txt");
  unsigned long long A, B, X, Y;
  fin >> A >> B;
  X = (A - B) / 2;
  Y = A - X;
  if ((X ^ Y) == B) {
    fout << X << " " << Y << endl;
  }
  else
  fout << "-1" << endl;
}