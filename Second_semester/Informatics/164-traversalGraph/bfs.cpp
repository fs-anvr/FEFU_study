#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int bfs (int cur, int N, vector<vector<int>> &graph);

int main ()
{
    int N, S;
    std::cin >> N >> S;
    S--;
    vector<vector<int>> graph(N);


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int b;
            std::cin >> b;
            if (b != 0)
            {
                graph[i].push_back(j);
            }
        }
    }


    cout << bfs(S, N, graph);
    return 0;
}

int bfs (int cur, int N, vector<vector<int>> &graph)
{
    bool *seen = new bool[N];
    for (int i = 0; i < N; ++i) seen[i] = false;

    queue<int> Queue;
    Queue.push(cur);
    while (!Queue.empty())
    {
        int t = Queue.front();
        seen[t] = true;
        Queue.pop();
        for (int i : graph[t])
        {
            if (!seen[i])
            {
                Queue.push(i);
                seen[i] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (seen[i]) count++;
    }
    return count;
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