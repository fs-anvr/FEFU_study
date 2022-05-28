#include <iostream>
#include <fstream>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    char mass[1000000];
    for (int i = 0; i < 1000000; i++){
        mass[i] = 'Z';
    }
    int i, j, N;
    char A;
    string strA;
    input >> N;
    for (int k = 0; k < N; k++) 
    {
        input >> A >> i >> j;
        for (int l = i - 1; l < j; l++) 
        {
            mass [l] = A;
        }
    }
    for (int k = 0; k < 1000000; k++) 
    {
        if (strA.find(mass[k]) == string::npos) 
        {
            strA += mass[k];
        }
    }
    output << strA.size();
}