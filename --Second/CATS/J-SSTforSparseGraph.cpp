#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

vector<int> parent, rang;


int find_set(int v);


struct Edge
{
    int first, second, weight;
};

bool comp (Edge & a, Edge & b)
{
    return a.weight < b.weight;
}



int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");


    int n, m;
    fin >> n >> m;
    vector<Edge> edges;

    parent.resize(n);
    rang.resize(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < m; ++i)
    {
        int a, b ,c;
        fin >> a >> b >> c;
        Edge ed = {a-1, b-1 ,c};
        edges.emplace_back(ed);
    }

    sort(edges.begin(), edges.end(), comp);

    int used_count = 0;
    int cost = 0;

    for (Edge e : edges)
    {
        if (find_set(e.first) != find_set(e.second))
        {
            cost += e.weight;
            ++used_count;
            int a = find_set(e.first);
            int b = find_set(e.second);
            if (a != b)
            {
                if (rang[a] < rang[b])
                    swap(a, b);
                parent[b] = a;
                if (rang[a] == rang[b])
                    rang[a]++;
            }
        }
    }

    if (used_count != n-1)
        fout << "-1";
    else
        fout << cost;


    fin.close();
    fout.close();
    return 0;
}


int find_set(int v)
{
    return (v == parent[v]) ? v : (parent[v] = find_set(parent[v]));
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
