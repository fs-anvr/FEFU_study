#include <iostream>

class vec2
{
public:
    int x, y;

    vec2(std::pair<int, int> a, std::pair<int, int> b){
        x = b.first - a.first;
        y = b.second - a.second;
    }
};


int vectorProduct(vec2 AB, vec2 BC)
{
    int product = AB.x * BC.y - AB.y * BC.x;
    if (product == 0)
        return 0;
    if (product > 0)
        return 1;
    if (product < 0)
        return -1;
};


int main()
{
    int n;
    std::cin >> n;

    if (n < 4)
    {
        std::cout << "YES";
        return 0;
    }

    auto* points = new std::pair<int, int>[n];

    for (int i = 0; i < n; ++i)
    {
        std::cin >> points[i].first;
        std::cin >> points[i].second;
    }


    int min_sign = 0, max_sign = 0, current_sign;
    for (int i = 0; i <= n; ++i)
    {
        vec2 AB(points[i], points[(i + 1) % n]);
        vec2 BC(points[(i + 1) % n], points[(i + 2) % n]);

        current_sign = vectorProduct(AB, BC);

        current_sign > max_sign ? max_sign = current_sign : 0;
        current_sign < min_sign ? min_sign = current_sign : 0;
    }

    if (std::abs(min_sign - max_sign) > 1)
        std::cout << "NO";
    else
        std::cout << "YES";

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