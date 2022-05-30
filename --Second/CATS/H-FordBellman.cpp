#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

struct Edge
        {
    int first;
    int second;
    int weight;
        };

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int N, M, S;
    fin >> N >> M >> S;
    --S;

    vector<Edge> graph;


    for(int i = 0; i < M; i++)
    {
        int idx1, idx2, val;
        fin >> idx1 >> idx2 >> val;
        Edge temp = {idx1 - 1, idx2 - 1, val};
        graph.push_back(temp);
    }

    vector<int> d(N);
    for (int & i : d)
        i = INT_MAX;
    d[S] = 0;

    for (int i = 0; i < N - 1; ++i)
        for (int j = 0; j < M; ++j)
        {
            int u = graph[j].first;
            int v = graph[j].second;
            int wei = graph[j].weight;

            if (d[u] != INT_MAX && d[v] > d[u] + wei)
                d[v] = d[u] + wei;
        }


    for (int ans : d)
        if (ans == INT_MAX)
            fout << ' ' <<  ' ';
        else
            fout << ans << ' ';
        

    fin.close();
    fout.close();
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