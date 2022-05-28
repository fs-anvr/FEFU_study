#include <fstream>
#include <iostream>
using namespace std;

int main ()  
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    int N;
    input >> N;
    for (int z = 0; z < N; z++) 
    {
        for (int y = 0; y < N; y++) 
        {
            for (int x = 0; x < N; x++) 
            {
                output << ((y + x + z) % N) + 1 << "\t";
            }
            output << "\n";
        }
    }
}