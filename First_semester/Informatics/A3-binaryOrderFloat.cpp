#include <iostream>
using namespace std;

int main()
{
  float number;
  cin >> number;
  int int_num = *(int*)&number;
  if (number == 0)
  {
    cout << 0;
  }
  else if(number < 1e-38 && number > -1e-38) 
  {
    cout << -126;
  }
  else
    cout <<((int_num >> 23) & 0xff) - 127;
}