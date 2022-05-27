#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#define MAXX 100001

using namespace std;


int main()
{

    ifstream fin ("input.txt");
    ofstream fout ("output.txt");


    int N, M, start;
    fin >> N >> M >> start;
    start--;
    vector<vector<pair<int,int>>> graph(N);
    for (int i = 0; i < M; ++i)
    {
        int on, tw, th;
        fin >> on >> tw >> th;
        graph[on-1].emplace_back(tw-1, th);
    }


    vector<int> distances (N, MAXX),  points (N);
    distances[start] = 0;
    set < pair<int,int> > queq;
    queq.insert (make_pair (distances[start], start));
    while (!queq.empty())
    {
        int buff = queq.begin()->second;
        queq.erase (queq.begin());

        for (size_t j=0; j<graph[buff].size(); ++j)
        {
            int to = graph[buff][j].first,
                    len = graph[buff][j].second;
            if (distances[buff] + len < distances[to])
            {
                queq.erase (make_pair (distances[to], to));
                distances[to] = distances[buff] + len;
                points[to] = buff;
                queq.insert (make_pair (distances[to], to));
            }
        }
    }

    for (int i = 0; i < N; ++i) fout << (distances[i] != MAXX ? distances[i] : -1) << ' ';
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
