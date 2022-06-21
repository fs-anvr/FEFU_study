#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int * used;
int * answer;
int ans_size = 0;
vector <int> * graph;
bool cycle = false;


void dfs(int v);


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n,m;
    fin >> n >> m;

    used = new int[n]{0};
    answer = new int[n];
    graph = new vector<int>[n];

    for (int i = 0; i < m; ++i)
    {
        int a,b;
        fin >> a >> b;
        graph[a - 1].push_back(b - 1);
    }

    for (int i = 0; i < n; ++i)
        if (!used[i])
            dfs(i);

    for (int i = 0; i < n/2; ++i)
        swap(answer[i], answer[n-i-1]);

    if (cycle)
        fout << "-1";
    else
        for (int i = 0; i < ans_size; ++i)
            fout << answer[i] + 1 << ' ';
        
    fin.close();
    fout.close();
    return 0;
}


void dfs(int v)
{
    used[v] = 1;
    for (int i : graph[v])
        if (used[i] == 0)
            dfs(i);
        else if (used[i] == 1)
        {
            cycle = true;
            return;
        }
    answer[ans_size++] = v;
    used[v] = 2;
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