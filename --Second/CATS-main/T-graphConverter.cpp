#include <fstream>
#include <vector>
#include <string>

class Edges
{
public:
    int N = 0, M = INT_MIN;
    std::vector<std::pair<int,int>> edges;

    Edges() = default;

    explicit Edges(int n) : N(n){}

    void readEdges(std::ifstream & fin)
    {
        fin >> M;
        for (int i = 0; i < M; ++i)
        {
            int a, b; fin >> a >> b;
            edges.emplace_back(a - 1, b - 1);
        }
    }

    void readLists(std::ifstream & fin)
    {
        for (int i = 0; i < N; ++i)
        {
            int size; fin >> size;

            for (int j = 0; j < size; ++j)
            {
                int a;
                fin >> a;
                edges.emplace_back(i, a - 1);
            }
        }
        M = (int)edges.size();
    }

    void readMatrix(std::ifstream & fin)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                int a; fin >> a;
                if (a != 0)
                    edges.emplace_back(i, j);
            }
        M = (int)edges.size();
    }

    void print(std::ofstream & fout)
    {
        fout << N << ' ' << M << '\n';
        for (std::pair<int,int> & edge : edges)
            fout << edge.first + 1 << ' ' << edge.second + 1 << '\n';
    }
};


class Lists
{
public:
    int N{};
    std::vector<std::vector<int>> lists;

    Lists() = default;

    explicit Lists(int n): N(n)
    {
        lists.resize(n);
    }

    void readLists(std::ifstream & fin)
    {
        for (int i = 0; i < N; ++i)
        {
            int size; fin >> size;

            for (int j = 0; j < size; ++j)
            {
                int a;
                fin >> a;
                lists[i].push_back(a - 1);
            }
        }
    }

    void readEdges(std::ifstream & fin)
    {
        int M;
        fin >> M;
        for (int i = 0; i < M; ++i)
        {
            int a, b; fin >> a >> b;
            lists[a - 1].push_back(b - 1);
        }
    }

    void readMatrix(std::ifstream & fin)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                int a; fin >> a;
                if (a != 0)
                    lists[i].push_back(j);
            }
    }

    void print(std::ofstream & fout)
    {
        fout << N << '\n';
        for (int i = 0; i < N; ++i)
        {
            fout << lists[i].size() << ' ';
            for (int & j: lists[i])
                fout << j + 1 << ' ';
            fout << '\n';
        }
    }
};


class Matrix
{
public:
    int N{};
    std::vector<std::vector<int>> matrix;

    Matrix() = default;

    explicit Matrix(int n): N(n)
    {
        matrix.resize(n, std::vector<int>(n, 0));
    }

    void readMatrix(std::ifstream & fin)
    {
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
            {
                int a; fin >> a;
                matrix[i][j] = a;
            }
    }

    void readEdges(std::ifstream & fin)
    {
        int M;
        fin >> M;
        for (int i = 0; i < M; ++i)
        {
            int a, b; fin >> a >> b;
            matrix[a - 1][b - 1] = 1;
        }
    }

    void readLists(std::ifstream & fin)
    {
        for (int i = 0; i < N; ++i)
        {
            int size; fin >> size;
            for (int j = 0; j < size; ++j)
            {
                int a; fin >> a;
                matrix[i][a - 1] = 1;
            }
        }
    }

    void print(std::ofstream & fout)
    {
        fout << N << '\n';
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                fout << matrix[i][j] << ' ';
            fout << '\n';
        }
    }
};


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    std::string prev, next;
    fin >> prev >> next;

    int N;
    fin >> N;

    if (next == "edges")
    {
        Edges graph(N);
        if (prev == "edges")
            graph.readEdges(fin);
        else if (prev == "lists")
            graph.readLists(fin);
        else if (prev == "mat")
            graph.readMatrix(fin);

        graph.print(fout);
    }
    else if (next == "lists")
    {
        Lists graph(N);
        if (prev == "edges")
            graph.readEdges(fin);
        else if (prev == "lists")
            graph.readLists(fin);
        else if (prev == "mat")
            graph.readMatrix(fin);

        graph.print(fout);
    }
    else if (next == "mat")
    {
        Matrix graph(N);
        if (prev == "edges")
            graph.readEdges(fin);
        else if (prev == "lists")
            graph.readLists(fin);
        else if (prev == "mat")
            graph.readMatrix(fin);

        graph.print(fout);
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