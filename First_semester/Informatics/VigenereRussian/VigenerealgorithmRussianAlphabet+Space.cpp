#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    const int d_size = 34;
    char dictionary [d_size] {'Б','В','Ч','З','Д','Е','Ј','Ц','Ъ','Й','К','Л','М','Н','О','П','Р'
                        ,'Т','У','Ф','Х','Ж','И','Г','Ю','Ы','Э','Ш','Щ','Я','Ь','А','С',' '};
    string curr_str;
    getline (input, curr_str);
    int key_size = curr_str.size();
    char* key = new char[key_size];
    for (int i = 0; i < key_size; i++)
    {
        key[i] = curr_str[i];
    }

    while ( getline(input, curr_str) )
    {
        output << curr_str << "\n";
        for (int i = 0; i < curr_str.size(); i++)
        {
            for (int j = 0; j < d_size; j++)
            {
                if (dictionary[j] == key[i])
                   { output << dictionary[ (j + key[i % key_size] - 48) % d_size] << "\t";
                    output << dictionary[j] << "\t" <<  (int)key[i] << "\n"; }
            }
        }
    }
}