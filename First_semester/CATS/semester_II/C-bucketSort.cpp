#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int buckets = 52;
vector <string> bucketSort(vector <string> &vec, int n, int rank);
void print (vector <string> vec, ofstream &fout);

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");
    int n; fin >> n;
    vector<string> vec;
    for (int i = 0; i < n; ++i)
    {
        string b; fin >> b;
        vec.push_back(b);
    }
    print(bucketSort(vec, n, 0), fout);

}

vector <string> bucketSort(vector <string> &vec, int n, int rank)
{
    if (vec.empty() || n == 1) return vec;
    vector <string> sort[buckets];
    vector<string> ans;
    for (int i = 0; i < n; ++i)
    {
        int x;
        if(vec[i][rank] < 91)
            x = vec[i][rank] - 'A';
        else
            x = vec[i][rank] - 'a' + 26;
        sort[x].push_back(vec[i]);
    }
    rank++;
    for (int i = 0; i < buckets && rank < 3; ++i)
    {
        if (!sort[i].empty())
            sort[i] = bucketSort(sort[i], sort[i].size(), rank);
    }
    for (int i = 0; i < buckets; ++i)
    {
            for (int j = 0; j < sort[i].size(); ++j)
            {
                ans.push_back(sort[i][j]);
            }
    }
    return ans;
}

void print (vector <string> vec, ofstream &fout)
{
    for (int i = 0; i < vec.size(); ++i) fout << vec[i] << "\n";
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
