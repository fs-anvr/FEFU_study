/// задача решена методом динамического программирования по подмножествам
/// вы можете легко загуглить объяснение
/// для самых ленивых - https://brestprog.by/topics/bitmasks/

#include<fstream>

#define MAX INT16_MAX
#define TYPE int16_t
#define pow2(x) (1<<x)
#define min(a,b) (a<b?a:b)
using namespace std;


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    TYPE n;
    fin >> n;

    TYPE **graph = new TYPE*[n];
    for (int i = 0; i < n; ++i)
        graph[i] = new TYPE[n];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; ++j)
            fin >> graph[i][j];

    TYPE** dp = new TYPE*[pow2(n)];
    for (int i = 0; i < pow2(n); ++i)
        dp[i] = new TYPE[n];

    for (int i = 0; i < pow2(n); ++i)
        for (int j = 0; j < n; ++j)
            dp[i][j] = MAX;

    for (int i = 0; i < n; ++i)
        dp[pow2(i)][i] = 0;

    for (int mask = 0; mask < pow2(n); ++mask)
        for (int i = 0; i < n; ++i)
            if (dp[mask][i] != MAX)
                for (int j = 0; j < n; ++j)
                    if (graph[i][j] != -1 && (mask & pow2(j)) == 0)
                        dp[mask | pow2(j)][j] = min(dp[mask | pow2(j)][j], dp[mask][i] + graph[i][j]);

    TYPE shortcut = MAX;
    for (int i = 0; i < n; ++i)
        shortcut = min(shortcut, dp[pow2(n) - 1][i]);

    fout << shortcut;
    return 0;
}