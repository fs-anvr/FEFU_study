#include <fstream>
#include <vector>
#include <set>

using namespace std;

class BinaryHeap
{
public:
    vector<unsigned long long> body;
    int size = 0;

    explicit BinaryHeap(int N)
    {
        size = 0;
        body.resize(N + 1);
    }

    void swap(int a, int b)
    {
        unsigned long long temp = body[a];
        body[a] = body[b];
        body[b] = temp;
    }

    unsigned long long top()
    {
        if (size == 0)
            return INT_MIN;
        return body[1];
    }

    void insertMax(unsigned long long node)
    {
        body[++size] = node;
        for (int i = size; i > 1 && body[i] > body[i/2]; i /= 2)
        {
            swap(i, i / 2);
        }
    }

    unsigned long long deleteMax()
    {
        unsigned long long max = body[1];
        int index = 1;
        body[1] = body[size--];
        for (;;)
        {
            int left = index * 2;
            int right = left + 1;
            int largest = index;
            if (left <= size && body[left] > body[index])
                largest = left;
            if (right <= size && body[right] > body[largest])
                largest = right;
            if (largest == index)
                break;
            swap(index, largest);
            index = largest;
        }

        return max;
    }
};


int main()
{
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;
    BinaryHeap thirst(n);

    for (int i = 0; i < n; ++i)
    {
        unsigned long long temp;
        fin >> temp;
        thirst.insertMax(temp);
    }

    for (int i = 0; i < m; ++i)
    {
        unsigned long long temp = thirst.deleteMax();
        temp /= 10;
        thirst.insertMax(temp);
    }

    unsigned long long min_thirst = 0;
    for (unsigned long long it : thirst.body)
    {
        min_thirst += it;
    }

    fout << min_thirst;

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