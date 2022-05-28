/*
ЭТО САМЫЙ ГРЯЗНЫЙ КОД НА СВЕТЕ
*/


#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

bool comp (pair<char,size_t> a, pair<char,size_t> b) {
    return a.second < b.second;
}

string normalize (string &str)
{
    if (str == "") str = "1";
    if (str == "-") str = "-1";
    if (str == "+") str = "1";
    return str;
}
int main() {
    string phrase;
    double a = 0, b = 0, c = 0;
    vector<pair<char, size_t>> poss;
    cin >> phrase;
    size_t pos = 0;
    while ((pos = phrase.find("+")) != string::npos)
    {

        phrase.replace(pos, 1, "#");
        poss.emplace_back('+', pos);
    }
    while ((pos = phrase.find("-")) != string::npos)
    {
        phrase.replace(pos, 1, "#");
        poss.emplace_back('-', pos);
    }
    sort (poss.begin(), poss.end(), comp);
    string str;
    if (poss.size() != 0)
    {
        str.append(phrase, 0, poss[0].second);
        string sign; sign = poss[0].first;
        if (str[0] == '#') str.replace(0, 1, sign);
        if (str != "") {
            if (str[str.size() - 1] == 'a') {
                str.erase(str.size() - 1);
                normalize(str);
                a = stod(str);
            } else if (str[str.size() - 1] == 'b') {
                str.erase(str.size() - 1);
                normalize(str);
                b = stod(str);
            } else {
                normalize(str);
                c = stod(str);
            }
            str.clear();
        }
    }
    for (size_t i = 0; i < poss.size(); ++i)
    {
        pos = poss[i].second;
        size_t count;
        if (i == poss.size()-1) count = phrase.size() - poss[i].second;
        else count = poss[i+1].second - poss[i].second;
        str.append(phrase, pos, count);
        string sign; sign += poss[i].first;
        if (str[0] == '#') str.replace(0, 1, sign);
        if (str != "") {
            if (str[str.size() - 1] == 'a') {
                str.erase(str.size() - 1);
                normalize(str);
                a = stod(str);
            } else if (str[str.size() - 1] == 'b') {
                str.erase(str.size() - 1);
                normalize(str);
                b = stod(str);
            } else {
                normalize(str);
                c = stod(str);
            }
            str.clear();
        }
    }
    cout << fixed;
    cout.precision(3);
    if (b && c)
    {
        double d = sqrt(b * b - 4 * a * c);
        double x1 = (-b + d) / (2 * a);
        double x2 = (-b - d) / (2 * a);
        std::cout << std::min(x1, x2) << ' ' << std::max(x1, x2);
    }
    else if (b)
    {
        double x1 = 0;
        double x2 = -b / a;
        std::cout << std::min(x1, x2) << ' ' << std::max(x1, x2);
    }
    else if (c)
    {
        double x = sqrt(-c / a);
        std::cout << -x << " " << x;
    }
    else
    {
        std::cout << "0.000 0.000";
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