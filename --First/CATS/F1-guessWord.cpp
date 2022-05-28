#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    string word, moves;
    getline (input, word);
    getline (input, moves);

    char* curr_word = new char [word.length()];
    
    for (int i = 0; i < word.length(); i++)
        curr_word[i] = '.';

    for (int i = 0; i < moves.length(); i++) 
    {
        for (int j = 0; j < word.length(); j++) 
        {
            if (moves[i] == word[j]) 
            {
                if (curr_word[j] == '.')
                    curr_word[j] = word[j];
                else
                    curr_word[j] = '.';
            }
        }
    }

    for (int i = 0; i < word.length(); i++) 
    {
        output << curr_word[i];
    }
    return 0;
}