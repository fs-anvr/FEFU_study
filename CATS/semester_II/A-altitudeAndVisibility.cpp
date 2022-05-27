#include <fstream>
#include <stack>
#include <vector>

struct unit {
    size_t height;
    int left, right;
};

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n; fin >> n;
    std::vector<unit> heights(n,{0,-1,-1});
    std::stack<size_t> ids;
    for(int i = 0; i < n; ++i) {fin >> heights[i].height;}

    for(int i = 0; i < n; ++i)
    {
        while(!ids.empty() && heights[ids.top()].height < heights[i].height)
        {
            heights[ids.top()].right = i;
            ids.pop();
        }
        ids.push(i);
    }
    while(!ids.empty()) ids.pop();
    for(int i = n - 1; i > -1; --i)
    {
        while(!ids.empty() && heights[ids.top()].height < heights[i].height) {
            heights[ids.top()].left = i;
            ids.pop();
        }
        ids.push(i);
    }

    for(int i = 0; i < n; ++i) {
        int ans = 0;
        if(heights[i].left >= 0) {
            ans = i - heights[i].left;
        }

        if(heights[i].right >= 0 &&
           (heights[i].right - i < ans || ans == 0)) {
            ans = heights[i].right - i;
        }

        fout << ans << " ";
    }

    fin.close();
    fout.close();
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
