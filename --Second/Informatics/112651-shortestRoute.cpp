#include <iostream>
#include <vector>
#include <string>

using namespace std;
#define MAXX 100001
int main()
{

    int N, start, finish;
    cin >> N;
    vector<vector<pair<int,int>>> graph(N);

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int b;
            cin >> b;
            if (b != 0)
            {
                graph[i].emplace_back(j, b);
                graph[j].emplace_back(i, b);
            }
        }
    }
    cin >> start >> finish;
    start--;
    finish--;


    vector<int> distances(N),  points(N);
    for (size_t i = 0; i != N; ++i)
    {
        distances[i] = MAXX;
    }
    distances[start] = 0;
    vector<bool> checked(N);


    for (int i = 0; i < N; ++i)
    {
        int shortest = -1;
        for (int j = 0; j < N; ++j)
        {
            if (!checked[j] && (shortest == -1 || distances[j] < distances[shortest]))
            {
                shortest = j;
            }
        }
        if (distances[shortest] == MAXX)
        {
            break;
        }
        checked[shortest] = true;
        for (size_t j = 0; j < graph[shortest].size(); ++j)
        {
            int to = graph[shortest][j].first;
            int length = graph[shortest][j].second;
            if (distances[shortest] + length < distances[to])
            {
                distances[to] = distances[shortest] + length;
                points[to] = shortest;
            }
        }
    }
    if (distances[finish] == MAXX)
    {
        cout << 0;
        return 0;
    }

    cout << distances[finish] << '\n';
    string answer;
    for (int cur = finish; cur != start; cur = points[cur]) answer = to_string(cur+1) + " " + answer;
    answer = to_string(start+1) + " " + answer;
    cout << answer;
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