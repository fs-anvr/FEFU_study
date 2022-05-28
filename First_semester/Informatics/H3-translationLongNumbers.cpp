#include <iostream>
#include <fstream>
#include <string>
const int OSN = 10000;
void READ_long_num (long *long_num , std::ifstream &in, long OSN_m);
void WRITE_long_num (long *long_num, std::ofstream &out, long OSN_m);
long DIVIDE_long_short (long* first, long second, long* result);
void TRANSLATE_10_to_any (long *long_num, long *result, long OSN_r);

int main () 
{
    std::ifstream in ("input.txt");
    std::ofstream out ("output.txt");
    long OSN_f, OSN_r;
    in >> OSN_f >> OSN_r;

    std::string str;
    getline (in, str);
    str.clear();

    long* first = new long [10000]{0};
    long* result = new long [10000]{0};


    READ_long_num (first, in, OSN_f);
    if (first[0] == 0)
    {
        out << 0;
        return 0;
    }
    TRANSLATE_10_to_any(first, result, OSN_r);
    WRITE_long_num(result, out, OSN_r);

    return 0;
}



void READ_long_num (long *long_num , std::ifstream &in, long OSN_m)
{
    long_num[0] = 1;
    char curr;
    while (in.get(curr))
    {
        for (int i = long_num[0]; i > 0; i--)
        {
            long_num[i+1] += (long_num[i] * OSN_m) / OSN;
            long_num[i] = (long_num[i] * OSN_m) % OSN;
        }

        long_num[1] += curr > 64 ? curr - 55 : curr - 48;

        if (long_num [long_num[0] + 1] > 0)
            long_num[0]++;
    }
    while (long_num[ long_num[0] ] == 0 && long_num[0] > 0)
        long_num[0]--;
}

void WRITE_long_num (long *long_num, std::ofstream &out, long OSN_m)
{
    for ( int i = long_num[0]; i > 0 ; i--)
    {
        out << (long_num[i] < 10 ? (char)(long_num[i] + 48) : (char)(long_num[i] + 55));
    }
}


long DIVIDE_long_short (long* first, long second, long* result)
{
    long balance = 0;
    for (int i = first[0]; i > 0; i--)
    {
        balance = balance * OSN + first[i];
        result[i] = balance / second;
        balance = balance % second;
    }
    result[0] = first[0];
    for (int i = first[0]; result[i] == 0 && i > 0; i--)
        result[0]--;
    return balance;
}


void TRANSLATE_10_to_any (long *long_num, long *result, long OSN_r)
{
    long* res_1 = new long [10000]{0};
    long* res_2 = new long [10000]{0};
    result[0] = 1;
    long i = 1;
    result[i++] = DIVIDE_long_short(long_num, OSN_r, res_1);
    while (res_1[0] > 1 ? true : (res_1[1] >= OSN_r))
    {
        result[i++] = DIVIDE_long_short(res_1, OSN_r, res_2);
        res_1 = res_2;
        result[0]++;
    }
    result[i++] = res_1[1];
    result[0]++;
    while (result[result[0]] == 0 && result[0] > 0)
        result[0]--;
}