#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#define primal 31
using namespace std;


int main() {

    string line, substr;
    getline(cin, line);
    getline(cin, substr);
    size_t line_s = line.size();
    size_t sub_s = substr.size();

    vector<size_t> exp(line_s);
    exp[0] = 1;
    for (size_t i = 1; i < exp.size(); ++i)
    {
        exp[i] = exp[i - 1] * primal;
    }

    vector<size_t> line_hash(line_s);
    for (size_t i = 0; i < line_s; ++i)
    {
        line_hash[i] = (line[i] - 'a' + 1) * exp[i];
        if (i)
        {
            line_hash[i] += line_hash[i - 1];
        }
    }

    size_t h_s = 0;
    for (size_t i = 0; i < sub_s; ++i)
    {
        h_s += (substr[i] - 'a' + 1) * exp[i];
    }

    for (size_t i = 0; i + sub_s - 1 < line_s; ++i)
    {
        size_t cur_h = line_hash[i+ sub_s - 1];
        if (i)
        {
            cur_h -= line_hash[i - 1];
        }
        if (cur_h == h_s * exp[i])
        {
            cout << i << ' ';
        }
    }

    return 0;
}
/*
⠄⠄⠄⠄⣠⣄⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⣼⡟⠉⠉⠄⠄⠄⠄⢀⣀⣀⣀⡀⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢿⣇⠄⠄⠄⠄⣠⣶⣿⠿⣿⣿⡿⣷⡀⠸⣿⣶⡀⠄⠄
⠄⠄⠄⠘⢿⣆⠄⣠⣾⣿⣿⣿⣶⣿⣿⣶⣿⠁⠄⣠⣿⡇⠄⠄
⠄⠄⠄⠄⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢛⣁⣤⣴⣿⠟⠁⠄⠄
⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⠁⠄⠄⠄⠄
⠄⠄⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⣿⣿⡟⠉⠉⠄⠄⠈⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢸⣿⣿⠁⠄⠄⠄⠄⠄⢻⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⣾⣿⠇⠄⠄⠄⠄⠄⠄⠄⢿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠹⢿⠁⡀⠄⠄⠄⠄⠄⠄⠸⣿⣶⡄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄
 */