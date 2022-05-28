#include <iostream>
#include <math.h>
#include <stack>
#include <string>
using namespace std;

bool operation (char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

int main() {
    string phrase; getline(cin, phrase);
    stack <double> s;
    for (size_t i = 0; i < phrase.size(); ++i)
    {
        if (isdigit(phrase[i]))
        {
            string number;
            while (i < phrase.size() && isdigit(phrase[i])) number += phrase[i++];
            i--;
            s.push(stod(number));
        }
        else if (operation(phrase[i]))
        {
            if (s.size() < 2)
            {
                cout << "ERROR";
                return 0;
            }
            double n2 = s.top();
            s.pop();
            double n1 = s.top();
            s.pop();
            switch (phrase[i]) {
                case '+':
                    s.push(n1 + n2);
                    break;
                case '-':
                    s.push(n1 - n2);
                    break;
                case '*':
                    s.push(floor(n1 * n2));
                    break;
                case '/':
                    s.push(floor(n1 / n2));
                    break;
                }
        }
    }
    if (s.size() == 1 ) cout << (int)floor(s.top());
    else cout << "ERROR";
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