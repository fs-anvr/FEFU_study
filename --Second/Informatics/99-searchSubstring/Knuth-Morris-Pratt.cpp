#include <iostream>
#include <string>
#include <vector>

static void pref_func (std::string str, size_t *mass);
static int N = 50000;
int main() {
    std::string str, comp;
    std::cin >> str;
    std::cin >> comp;
    size_t *mass = new size_t [N];
    pref_func(comp, mass);
    size_t n = str.length();
    size_t m = comp.length();
    for (size_t k = 0, i = 0; i < n; ++i)
    {
        while ((k > 0) && (comp[k] != str[i]))
            k = mass[k - 1];

        if (comp[k] == str[i])
            k++;

        if (k == m)
            std::cout << (i - m + 1) << ' ';

    }

    return 0;
}

static void pref_func (std::string str, size_t *mass) {
    size_t n = str.size();
    for (int i = 1; i < n; ++i) {
        size_t j = mass[i-1];
        while (j > 0 && str[i] != str[j])
            j = mass[j-1];
        if (str[i] == str[j])  ++j;
        mass[i] = j;
    }
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