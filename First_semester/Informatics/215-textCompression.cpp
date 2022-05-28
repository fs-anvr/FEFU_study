#include <iostream>
#include <fstream>
#include <vector>
#include <ctime>
#include <string>
using namespace std;

int main() {
    ifstream input("input.txt");
    ofstream output("output.txt");

    int r, n;
    input >> r >> n;
    string str1, str2;
    vector <pair <string, string> > Replays(r); //создаём вектор пар заменяемый элемент\на что меняем

    getline(input, str1);

    for (int i = 0; i < r; i++)
    {
        getline(input, str1);
        getline(input, str2);
        Replays[i] = make_pair(str1, str2);
    }

    //основной алгоритм архивации

    for (int i = 0; i < n; i++)
    {
        getline(input, str1);  // считываем одну строку
        vector <string> cur_str(str1.size() + 1); // создаём вектор строк, чтобы добавлять по одному символу и иметь предыдущие "версии строки"
        for (int k = 1; k < str1.size() + 1; k++)
        {
            cur_str[k] = cur_str[k - 1] + str1[k - 1]; // добавление предыдущей версии строки и следующего символа
            for (int f = 0; f < r; f++)
            {
                if (Replays[f].first.size() <= k)  // проверяем, поместится ли заменяемая строка в текущую
                    if ((str1.compare(k - Replays[f].first.size(), Replays[f].first.size(), Replays[f].first) == 0) && // проверяем, включает ли текущаяя строка в себя заменяемую
                       (cur_str[k - Replays[f].first.size()].size() + 1 < cur_str[k].size())) // проверяем, будет ли строка с заменой короче чем строка без замены
                {
                        cur_str[k] = cur_str[k - Replays[f].first.size()] + Replays[f].second; // берём значение строки на *длина замены* символов раньше и добавляем замену
                }
            }
        }
        output << cur_str[str1.size()] << "\n"; // выводим строку
    }
}