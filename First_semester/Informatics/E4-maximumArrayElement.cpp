#include <iostream>
using namespace std;

int main () 
{
    int n, curr, max = -1000000;
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> curr;
        if (max < curr) max = curr;
    }
    cout << max;
}