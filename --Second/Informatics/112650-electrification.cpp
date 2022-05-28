#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<pair<int, int>>> graph;
vector<pair<int, int>> ost;
int * colors;
bool* seen;
int N;

void minDistance();

int main()
{
    cin >> N;

    graph.resize(N);
    seen = new bool[N];
    colors = new int [N];


    for (int i = 0; i < N; ++i)
    {
        seen[i] = false;
        colors[i] = i;
    }


    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            int b;
            std::cin >> b;
            if (b != 0)
            {
                graph[i].emplace_back(j, b);
                graph[j].emplace_back(i, b);
            }

        }
    }

    minDistance();
    sort(ost.begin(), ost.end());

    for (pair<int,int> i : ost) cout << i.first+1 << ' ' << i.second+1 << '\n';

    delete [] colors;
    delete [] seen;

    return 0;
}

void minDistance()
{
    for (int k = 0; k < N-1; ++k)
    {
        int iMin, jMin, minDist = 1e7;
        for (int i = 0; i < N; ++i)
        {
            for (pair<int, int> j: graph[i])
            {
                if (colors[i] != colors[j.first] && j.second < minDist)
                {
                    iMin = i;
                    jMin = j.first;
                    minDist = j.second;
                }
            }
        }
        ost.emplace_back(iMin, jMin);
        int c = colors[jMin];
        for (int i = 0; i < N; ++i)
        {
            if (colors[i] == c) colors[i] = colors[iMin];
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