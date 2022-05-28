#include <iostream>

using namespace std;

int main()
{
  long long n;
  int i;
  cin >> n >> i;
  cout << (n | (1 << i)) << endl;
}