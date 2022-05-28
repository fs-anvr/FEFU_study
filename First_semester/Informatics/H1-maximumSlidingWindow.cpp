#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

struct SlidingWindow
{
    deque<pair<int,int>> d;
    int l, r;

    SlidingWindow()
    {
        l = r = 0;
    }

    void push_back(int x)
    {
        while(!d.empty() && d.back().first <= x) d.pop_back();
        d.emplace_back(x,r++);
    }

    void pop_front()
    {
        if(d.front().second == l++) d.pop_front();
    }

    int max()
    {
        return d.empty() ? -1 : d.front().first;
    }
};

int main()
{
    ifstream fin ("input.txt");
    ofstream fout ("output.txt");

    SlidingWindow window;
    int n;
    fin >> n;


    long long* mass = new long long [n];
    for (int i = 0; i < n; i++)
        fin >> mass[i];


    int m;
    fin >> m;


    char cur;
    int right=0;
    window.push_back(mass[0]);
    for (int i = 0; i < m; i++)
    {
        fin >> cur;

        if (cur == 'R')
            window.push_back(mass[++right]);
        else
            window.pop_front();

        fout << window.max() << " ";
    }
    return 0;
}