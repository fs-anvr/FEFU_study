#include <iostream>
#include <fstream>
#include <map>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    map <int, int> smass;
    int n, x;
    input >> n;
    for (int i = 0; i < n; i++) 
    {
        input >> x;
        smass[x] = ++smass[x];
    }
    for (auto it = smass.begin(); it != smass.end(); it++) 
    {
        output << it-> first << " " << it-> second << "\n";
    }
}