#include <iostream>
#include <fstream>

int main () 
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");
    int N;
    in >> N;

    long long curr, max;
    long long* mass = new long long [N];

    for (int i = 0; i < N; i++)
    {    
        in >> curr;
        mass[i] = curr;
    }
    long long* mass_max = new long long [N]{0};
    mass_max[N - 1] = N - 1;
    for (int i = N - 1; i > 0; i--)
    {
            int k = i;
            while (mass[i - 1] >= mass[k] && k < N - 1 && mass_max[k] != k)
            {
                k = mass_max[k];
            }
            if (mass[i - 1] < mass[k])
                mass_max[i - 1] = k;
            else
                mass_max[i - 1] = i - 1;
    }
    for (int i = 0; i < N; i++)
        out << mass[mass_max[i]] << "\t";
    return 0;
}