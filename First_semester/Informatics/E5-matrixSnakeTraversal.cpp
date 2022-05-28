#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    int N, count = 0;
    input >> N;
    int mass[100][100];
    for (int y = 0; y < N; y++) 
    {
        if (y % 2 == 0)
            for (int x = 0; x < N; x++) 
            {
                count++;
                mass [y][x] = count;
            }
        else
            for (int x = N - 1; x > -1; x--) 
            {
                count++;
                mass[y][x] = count;
            }
    }
    for (int y = 0; y < N; y++) 
    {
        for (int x = 0; x < N; x++)
            output << mass[y][x] << "\t";
        output << "\n";
    }
}