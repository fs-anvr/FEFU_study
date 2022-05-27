#include <iostream>
#include <string>
using namespace std;
int cond[8][4] =
        {
                {1, -1, -1, 2},
                {1, 3, 4, -1},
                {1, -1, -1, -1},
                {5, -1, -1, 6},
                {7, -1, -1, -1},
                {5, -1, -1, -1},
                {5, -1, -1, -1},
                {7, 3, -1, -1}
        };
bool answer[] = {0, 1, 0, 0, 0, 1, 0, 1};
string digit = "0123456789";
string sign = "+-";
string sep = ".";
string ex    = "Ee";
int search (char ch)
{
    for (int i = 0; i < digit.size(); ++i) if (ch == digit[i]) return 0;
    for (int i = 0; i < sign.size(); ++i) if (ch == sign[i]) return 3;
    for (int i = 0; i < sep.size(); ++i) if (ch == sep[i]) return 2;
    for (int i = 0; i < ex.size(); ++i) if (ch == ex[i]) return 1;
    return -1;
}
int main() {
    string num;
    cin >> num;
    int curr_cond = 0;
    bool flag = true;
    for (int i = 0; i < num.size() && flag; i++)
    {
        int sost = search(num[i]);
        if (sost >= 0 && cond[curr_cond][sost] >= 0) curr_cond = cond[curr_cond][sost];
        else flag = false;
    }
    if (flag && answer[curr_cond]) cout << "YES";
    else cout << "NO";
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