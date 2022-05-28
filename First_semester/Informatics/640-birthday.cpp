#include <iostream>

using namespace std;
bool leap(int y) {
    if ((y % 400 == 0) | ((y % 100 != 0) & (y % 4 == 0))) return true;
    return false;
}

int main() {
    int year[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dr, mr, d, m, y;
    int sum = 0;
    cin >> dr >> mr;
    cin >> d >> m >> y;
    if ((m > mr) || ((m == mr) & (d > dr))) {
        for (int i = (m - 1); i < 12; i++) {
            if ((i == 1) & leap(y) ) ++sum;
            sum += year[i];
        }
    m = 1;
    y++;
    }
    if ((dr == 29) && (mr == 2)) {
        while (!leap(y)) {sum += 365; y++;}
    }
    for (int i = (m - 1); i < (mr - 1); i++) {
        if ((i == 1) & (leap(y))) ++sum;
            sum += year[i];
    }

    sum -= d; sum += dr;
    cout << sum;

}