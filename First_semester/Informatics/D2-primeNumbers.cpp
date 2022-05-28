#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
  ifstream input ("input.txt");
  ofstream output ("output.txt");
  long long n = 8000, p = 2, count = 0, t;
  input >> t;
    vector <int> a (n+1, 1);
    if (t > 0)
    for (p = 2; p < n + 1; p++)
    {
        if (a[p] != 0)
        {
            output << p << " ";
            count++;
            if (count >= t) break;
            if (p * p < n + 1)
            {
                for (long long i = p * p; i < n + 1; i += p)
                {
                    a[i] = 0;
                }
            }
        }
    }
    else return 0;
}