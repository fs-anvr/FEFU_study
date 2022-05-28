#include <iostream>
#include <fstream>
#include <string>


const int OSN = 10000;


void READ_long_num (long *long_num , std::ifstream &in);
void WRITE_long_num (long *long_num, std::ofstream &out);
void SUBTRACT_long_num (long *first, long *second, long *result);

int main () 
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");

    long* first = new long [OSN]{0};
    long* second = new long [OSN]{0};
    long* result = new long [OSN]{0};

    READ_long_num(first, in);
    READ_long_num(second, in);


    SUBTRACT_long_num(first, second, result);
    WRITE_long_num (result, out);
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
void SUBTRACT_long_num (long *first, long *second, long *result)
{
    long balance = 0;
    for (int i = 1; i <= first[0]; i++)
    {
        if (first[i] - second[i] - balance >= 0)
        {
            result[i] = first[i] - second[i] - balance;
            balance = 0;
        }
        else
        {
            result[i] = first[i] - second[i] - balance + OSN;
            balance = 1;
        }
    }
    result[0] = first[0];
    while (result[ result[0] ] == 0 && result[0] > 0)
        result[0]--;
}