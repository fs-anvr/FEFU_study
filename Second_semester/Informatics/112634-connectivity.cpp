#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
bool* seen;

void dfs(int curr, int father);

int main()
{
    int N;
    std::cin >> N;

    graph.resize(N);
    seen = new bool[N];
    for (int i = 0; i < N; ++i) seen[i] = false;


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int b;
            std::cin >> b;
            if (b != 0)
            {
                graph[i].push_back(j);
                graph[j].push_back(i);
            }

        }
    }

    dfs(0, -1);

    bool flag = true;
    for (int i = 0; i < N; ++i) if (!seen[i]) flag = false;

    if (flag) std::cout << "YES";
    else std::cout << "NO";

    return 0;
}

void dfs(int curr, int father)
{
    seen[curr] = true;
    for (int sun_id : graph[curr])
    {
        if ((sun_id != father) && !seen[sun_id])
        {
            dfs(sun_id, curr);
        }
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