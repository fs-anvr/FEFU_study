#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    ifstream fin("shelter.in");
    ofstream fout("shelter.out");

    int n;
    fin >> n;
    vector<int> villages(n);

    for(int i = 0; i < n; i++) fin >> villages[i];

    int m;
    fin >> m;
    vector<pair<int,int>> shelters(m);

    int count = 0;
    for(int i = 0; i < m; i++)
    {
        fin >> count;
        shelters[i] = (make_pair(count,i+1));
    }

    sort(shelters.begin(),shelters.end());

    int result = 0;
    for(int i = 0; i < n; i++)
    {
        if(villages[i] > shelters[m-1].first)
            result = shelters[m-1].second;
        else if(villages[i] < shelters[0].first)
            result = shelters[0].second;
        else
        {
            int left = 0;
            int right = shelters.size() - 1;
            while (right - left > 1)
            {
                int middle = (left + right) / 2;
                if(villages[i] > shelters[middle].first)
                    left = middle;
                else
                    right = middle;
            }

            if(villages[i] - shelters[left].first < shelters[right].first - villages[i])
                result = shelters[left].second;
            else
                result = shelters[right].second;
        }
        fout << result << ' ';
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
