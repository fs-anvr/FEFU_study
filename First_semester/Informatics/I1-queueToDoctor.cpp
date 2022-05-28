#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n, k;
    int res = 0;
    queue<int> q;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        while (!q.empty())
        {
            if (q.front() <= t)
                q.pop();
            if (q.front() > t)
                break;
        }

        q.push(t + k);
        res = res < q.size() ?  q.size() : res;
    }
    cout << res - 1;
    return 0;
}