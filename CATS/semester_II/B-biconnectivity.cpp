#include <fstream>
#include <vector>
#define in_min(a, b) (in[a] < in[b] ? (a) : (b))

int *in, *up, timer = 0;
std::vector<std::vector<int>> graph;
std::vector<int> answers;

void dfs(int curr, int father);

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int N, M;
    fin >> N >> M;
    graph.resize(N);
    in = new int[N]{0};
    up = new int[N];
    for (int i = 0; i < N; ++i) up[i] = i;

    for (int line = 0, num1, num2; line < M; ++line) {
        fin >> num1 >> num2;
        graph[num1 - 1].push_back(num2 - 1);
        graph[num2 - 1].push_back(num1 - 1);
    }
    dfs(0, -1);
    fout << answers.size();
    for (int num : answers) fout << ' ' << num + 1;

    delete[] in;
    delete[] up;
    fin.close();
    fout.close();
    return 0;
}

void dfs(int curr, int father) {
    in[curr] = ++timer;
    bool flag = false;
    int children = 0;
    for (int sun_id : graph[curr]) {
        if ((sun_id != father) && (in[sun_id] < in[curr])) {
            if (in[sun_id] == 0) {
                ++children;
                dfs(sun_id, curr);
                if (in[up[sun_id]] >= in[curr]) flag = true;
                up[curr] = in_min(up[curr], up[sun_id]);
            }
            else up[curr] = in_min(up[curr], sun_id);
        }
    }
    if ((father == -1) && (children < 2)) flag = false;
    if (flag) answers.push_back(curr);
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
