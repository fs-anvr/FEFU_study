#include <iostream>
#include <math.h>
#include <bitset>
#include <string>
#include <fstream>

using namespace  std;

string bit_num (int num, int n)
{
    string result = "";
    while (num)
    {
        result = to_string(num % 2) + result;
        num /= 2;
    }
    while (result.length() < n)
    {
        result = "0" + result;
    }
    return result;
}

void PrintAll (int curr, int max, int n, ofstream &out)
{
    out << bit_num(curr, n) << "\n";
    if (++curr < max)
        PrintAll(curr, max, n, out);
}

int main()
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");

    int n;
    in >> n;
    int max = pow (2, n);
    PrintAll(0, max, n, out);
    in.close();
    out.close();
    return 0;
}