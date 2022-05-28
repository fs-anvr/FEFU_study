#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");

    int N, P, count, cont_sum;
    input >> N >> P;

    string curr_str;
    getline (input, curr_str);

    int* mass = new int [P];
    for (int i = 0; i < P; i++)
        mass[i] = 0;


    while ( getline (input, curr_str) )
    {
        count = 0;
        for (int i = 0; i < curr_str.length(); i++) 
        {
            if (curr_str[i] > 47 )
            {
            if (curr_str[i] < 58)
                count += curr_str[i] - 48;
            else
                count += curr_str[i] - 55;
            }
        }
        cont_sum = count % P;
        mass[cont_sum] = 1;
    }


    for (int i = 0; i < P; i++) 
    {
        if ( (mass[i] != 1) && (i < 876) ) 
        {
            cont_sum = i;
            for (int j = 1; j < 30; j++) 
            {
                if (j % 6 == 0)
                  output << "-";
                else if (cont_sum > 0) 
                {
                    if (cont_sum - 35 >= 0) 
                    {
                        cont_sum -= 35;
                        output << 'Z';
                    }
                    else if (cont_sum - 35 < 0) 
                    {
                        if (cont_sum < 10) 
                        {
                            output << cont_sum;
                            cont_sum = 0;
                        }
                        else 
                        {
                            output << (char)(cont_sum + 55);
                            cont_sum = 0;
                        }
                    }
                }
                else output << '0';
            }
            return 0;
        }
    }


    output << "Impossible";
    return 0;

}