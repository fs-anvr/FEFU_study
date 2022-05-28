#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main () 
{
    ifstream input ("input.txt");
    ofstream output ("output.txt");
    bool be = true;
    string text, str_delete, str_insert, final_str = "";
    int count, age_of_fire = 0;
    getline (input, text);
    getline (input, str_delete);
    getline (input, str_insert);

    count = 0;
    for (int i = 0; i < str_delete.size(); i++)
    {
        if (str_delete[i] == str_insert[i])
            count++;
    }
    if (count == str_delete.size())
    {
        output << -1;
        return 0;
    }
    while (be == true)
    {
        be = false;
        if (age_of_fire != 0)
        {
            text = final_str;
            final_str.clear();
        }
        for (int i = 0; i < text.size();i++) 
        {
                if(i + str_delete.size() < text.size() + 1)
                {
                    count = 0;
                    for (int j = 0; j < str_delete.size(); j++)
                    {
                        if (text[i + count] == str_delete[count])
                            count++;
                   }
                    if (count != str_delete.size())
                    {
                        final_str += text[i];
                    }
                    else
                    {
                        final_str += str_insert;
                        i += count - 1;
                        be = true;
                    }
                }
                else 
                {
                    final_str += text[i];
                }
        }
        age_of_fire++;
    }

    output <<final_str;
        
}