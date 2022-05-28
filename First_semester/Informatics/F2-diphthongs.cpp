#include <iostream>
#include <fstream>
#include <string>
using namespace std;


bool existence (char symbol)
{
    const int T = 6;
    char dictionary [T] { 'a', 'e', 'i', 'o', 'u', 'y'};

    for (int i = 0; i < T; i++)
        if (symbol == dictionary[i]){
            return true;
            return 0;
        }

    return false;
}


int main() 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");

    const int T = 6;
    char dictionary [T] { 'a', 'e', 'i', 'o', 'u', 'y'};

    int N;
    input >> N;
    string curr_string;
    getline (input, curr_string);


    string* mass = new string [N];

    for (int i = 0; i < N; i++)
    {
        getline (input, curr_string);
        mass[i] = curr_string;
    }

    int* mass_diftong = new int [N];
    for (int i = 0; i < N; i++)
        mass_diftong[i] = 0;

    bool check1, check2;
    int max_diftongs = 0;
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < mass[i].size() - 1; j++)
        {
            check1 = existence(mass[i][j]);
            check2 = existence(mass[i][j + 1]);
            if (check1 && check2) 
            {
                if (j > 0)
                    check1 = existence(mass[i][j - 1]);
                else check1 = false;
                if (j < mass[i].size() - 1)
                    check2 = existence(mass[i][j + 2]);
                else check2 = false;
                if ((!check1) && (!check2))
                {
                    mass_diftong[i]++;
                    if (mass_diftong[i] > max_diftongs)
                        max_diftongs = mass_diftong[i];
                }
            }
        }
    }
    for (int i = 0; i < N; i++)
    {
        if (mass_diftong[i] == max_diftongs)
        {
                output << mass[i] << "\n";
        }
    }

    return 0;
}