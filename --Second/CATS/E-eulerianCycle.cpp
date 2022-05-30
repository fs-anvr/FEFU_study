#include <fstream>
#include <vector>
#include <stack>
using namespace std;


int main() {
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int N, M;
    fin >> N >> M;

    vector<vector<int>> graph;
    graph.resize(N);

    for (int i = 0, first, second; i < M; ++i)
    {
        fin >> first >> second;
        graph[first - 1].push_back(second - 1);
        graph[second - 1].push_back(first - 1);
    }



    for (int i = 0; i < N; ++i)
    {
        if (graph[i].size() % 2 != 0 )
        {
            fout << "-1";
            return 0;
        }
    }

    stack<int> stak;
    stak.push (0);

    while (!stak.empty())
    {
        int v = stak.top();
        int i;

        for (i = 0; i < graph[v].size(); ++i)
            if (graph[v][i] != -1)
            {
                int h = graph[v][i];
                stak.push(h);
                graph[v][i] = -1;
                for (int & j : graph[h])
                    if (j == v)
                    {
                        j = -1;
                        break;
                    }
                break;
            }
        if (i == graph[v].size())
        {
            fout << v + 1 << ' ';
            stak.pop();
        }
    }

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