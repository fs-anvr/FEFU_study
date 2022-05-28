#include <iostream>
#include <vector>

std::vector<std::vector<int>> graph;
bool *seen;

void dfs(int curr, int father);

int main()
{
    int N, S;
    std::cin >> N >> S;
    S--;
    graph.resize(N);
    seen = new bool[N];

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
    dfs(S, -1);

    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        if (seen[i]) count ++;
    }
    std::cout << count;

    delete[] seen;
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