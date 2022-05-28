#include <iostream>
#include <fstream>
#include <string>


const int OSN = 10000;


void READ_long_num (long *long_num , std::ifstream &in);
void WRITE_long_num (long *long_num, std::ofstream &out);
void DIVIDE_long_short (long* first, long second, long* result, long &balance);

int main () 
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    long* first = new long [OSN]{0};
    long* result = new long [OSN]{0};

    READ_long_num(first, in);

    long sh_ort, balance = 0;
    in >> sh_ort;

    DIVIDE_long_short(first, sh_ort, result, balance);
    WRITE_long_num (result, out);
    out << "\n" << balance; 

    return 0;
}

void READ_long_num (long *long_num , std::ifstream &in)
{
    long_num[0] = 1;
    char curr;
    while (in.get(curr))
    {
        if (curr == '\n')
            break;
        for (int i = long_num[0]; i > 0; i--)
        {
            long_num[i+1] = long_num[i+1] + (long_num[i] * 10) / OSN;
            long_num[i] = (long_num[i] * 10) % OSN;
        }
        long_num[1] = long_num[1] + (curr - 48);
        if (long_num [long_num[0] + 1] > 0)
            long_num[0]++;
    }
}

void WRITE_long_num (long *long_num, std::ofstream &out)
{
    std::string osn_str = std:: to_string(OSN / 10);
    std::string curr;
    out << long_num[ long_num[0] ];
    for ( int i = long_num[0] - 1 ; i > 0 ; i--)
    {
        curr = std:: to_string (long_num[i]);
        while (osn_str.length() > curr.length())
            curr = '0' + curr ;
        out << curr ;
    }
}

void DIVIDE_long_short (long* first, long second, long* result, long &balance)
{
    for (int i = first[0]; i > 0; i--)
    {
        balance = balance * OSN + first[i];
        result[i] = balance / second;
        balance = balance % second;
    }
    result[0] = first[0];
    for (int i = first[0]; result[i] == 0 && i > 0; i--)
        result[0]--;
}