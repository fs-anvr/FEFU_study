#include <fstream>
#include <vector>
using namespace std;

class BinaryHeap
{
public:
    vector<long long> body;
    int size = 0;

    explicit BinaryHeap(int N)
    {
        size = 0;
        body.resize(N + 1);
    }

    void swap(int a, int b)
    {
        long long temp = body[a];
        body[a] = body[b];
        body[b] = temp;
    }

    long long top()
    {
        if (size == 0)
            return INT_MIN;
        return body[1];
    }

    void insertMax(long long node)
    {
        body[++size] = node;
        for (int i = size; i > 1 && body[i] > body[i/2]; i /= 2)
        {
            swap(i, i / 2);
        }
    }

    void insertMin(long long node)
    {
        body[++size] = node;
        for (int i = size; i > 1 && body[i] < body[i/2]; i /= 2)
        {
            swap(i, i / 2);
        }
    }

    long long deleteMax()
    {
        long long max = body[1];
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
    long long deleteMin()
    {
        long long min = body[1];
        int index = 1;
        body[1] = body[size--];
        for (;;)
        {
            int left = index * 2;
            int right = left + 1;
            int largest = index;
            if (left <= size && body[left] < body[index])
                largest = left;
            if (right <= size && body[right] < body[largest])
                largest = right;
            if (largest == index)
                break;
            swap(index, largest);
            index = largest;
        }

        return min;
    }
};


int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    int n;
    fin >> n;

    BinaryHeap bin_min(n);
    BinaryHeap bin_max(n);

    for (int i = 0; i < n; ++i)
    {
        int data;
        fin >> data;
            if (data <= bin_max.top())
                bin_max.insertMax(data);
            else
                bin_min.insertMin(data);

        while (bin_min.size + 1 <  bin_max.size)
            bin_min.insertMin(bin_max.deleteMax());
        while (bin_min.size > bin_max.size)
            bin_max.insertMax(bin_min.deleteMin());
        
        fout << bin_max.top() << ' ';
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
