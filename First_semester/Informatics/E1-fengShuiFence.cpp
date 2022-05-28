#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    vector <int> mass1;
    vector <int> mass2;
    int N, curr_a, count1 = 0, count2 = 0;
    input >> N;
    input >> curr_a;
    mass1.push_back(0);
    mass2.push_back(0);
    mass1.push_back(curr_a);
    mass2.push_back(curr_a);
    if (N > 1) 
    {
        for (int i = 1; i < N; i++) 
        {
            input >> curr_a;
            mass1.push_back(curr_a);
            mass2.push_back(curr_a);
        }
    }
    else 
    {
        output << curr_a;
        return 0;
    }
    mass1.push_back(0);
    mass2.push_back(0);
    for (int i = 1; i < N + 1; i++) 
    {
        if (i % 2 == 0) 
        {
            count2 += max(mass2[i], max(mass2[i+1] + 1, mass2[i-1] + 1)) - mass2[i];
            mass2[i] = max(mass2[i], max(mass2[i+1] + 1, mass2[i-1] + 1));
        }
        else 
        {
            count1 += max(mass1[i], max(mass1[i+1] + 1, mass1[i-1] + 1)) - mass1[i];
            mass1[i] = max(mass1[i], max(mass1[i+1] + 1, mass1[i-1] + 1));
        }
    }
    if (count1 > count2) 
        for (int i = 1; i < N + 1; i++)
            output << mass2[i] << "\t";
    else
        for (int i = 1; i < N + 1; i++)
            output << mass1[i] << "\t";
}