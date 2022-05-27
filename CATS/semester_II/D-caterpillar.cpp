#include <iostream>
#include <deque>
using namespace std;
struct caterpillar
{
    int down, up, length;
};
int main() {
    int L, N;
    cin >> L >> N;
    if (N == L)
    {
        cout << 0;
        return 0;
    }
    int *terrain = new int [N];
    for (int i = 0; i < N; ++i) cin >> terrain[i];
    int time = 0;
    caterpillar cat {0, 0, --L};
    deque<bool> deq;
    for (int i = 0; i <= L; ++i)
    {
        if (terrain[i] > terrain[i+1])
        {
            deq.push_front(true);
            cat.down++;
        }
        else
        {
            deq.push_front(false);
            cat.up++;
        }
    }
    if (cat.down <= cat.up || !deq.front()) time++;
    for (int i = L+1; i < N-1; ++i)
    {
        if (deq.back()) cat.down--;
        else cat.up--;
        deq.pop_back();
        if (terrain[i] > terrain[i+1])
        {
            deq.push_front(true);
            cat.down++;
        }
        else
        {
            deq.push_front(false);
            cat.up++;
        }
        if (cat.down <= cat.up || !deq.front()) time++;
    }
    cout << time;
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
