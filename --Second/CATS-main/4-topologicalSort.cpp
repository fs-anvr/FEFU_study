#include <fstream>
#include <vector>
#include <set>


std::vector<int> minTopologicalSort(std::vector<std::vector<int>> & graph, std::vector<int> degree);


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    
    std::vector<std::vector<int>> graph;
    std::vector<int> degree;

    int n, m;
    fin >> n >> m;

    graph.resize(n);
    degree.resize(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        fin >> a >> b;
        graph[--a].push_back(--b);
        degree[b]++;
    }

    std::vector<int> answer = minTopologicalSort(graph, degree);

    for (int i : answer)
        fout << i+1 << ' ';

    return 0;
}


std::vector<int> minTopologicalSort(std::vector<std::vector<int>> &graph, std::vector<int> degree)
{
    std::vector<int> answer;
    std::set<int> zero, first;

    for (int i = 0; i < degree.size(); i++)
        if (degree[i] == 0)
            zero.insert(i);


    while (!zero.empty())
    {
        int v = *zero.begin();
        zero.erase(zero.begin());
        answer.push_back(v);
        for (int to : graph[v])
        {
            degree[to]--;
            if (degree[to] == 0)
                first.insert(to);
        }
        if (zero.empty())
        {
            copy(first.begin(), first.end(), inserter(zero, zero.begin()));
            first.clear();
        }
    }

    return answer;
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