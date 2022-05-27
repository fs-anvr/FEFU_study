#include <iostream>
#include <cstring>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>

using namespace std;
using namespace chrono;

void randomVector (vector<int>& vec);

void shakerSort(vector<int>& vec);

void radixSort(vector<int>& vec);

void bubbleSort(vector<int> & vec, int start = INT_MIN);

void insertSort(vector<int> & vec);

void quickSort(vector<int> & vec, int start = INT_MIN, int end = INT_MAX);

void mergeSort(vector<int> & vec, int start = INT_MIN, int end = INT_MAX);

void MixedSort (vector<int> & vec, int start = INT_MIN, int end = INT_MAX);


int main()
{
    int M = 10; // количество тестов
    int N = 1e4;// количество данных

    cout << "Введите количество данных : ";
    cin >> N;

    cout << "Введите количество тестов для каждой сортировки: ";
    cin >> M;


    vector<int> vec(N);

    cout << "Bubble Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        bubbleSort(vec);
        auto chrono_end = steady_clock::now();
        cout <<((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }

    cout << "Insert Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        insertSort(vec);
        auto chrono_end = steady_clock::now();
        cout <<((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }

    cout << "Quick Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        quickSort(vec, 0, N-1);
        auto chrono_end = steady_clock::now();
        cout <<((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }

    cout << "Merge Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        mergeSort(vec, 0, N-1);
        auto chrono_end = steady_clock::now();
        cout <<((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }

    cout << "Quick Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        MixedSort(vec, 0, N);
        auto chrono_end = steady_clock::now();
        cout <<((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }

    cout << "Shaker Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        shakerSort(vec);
        auto chrono_end = steady_clock::now();
        cout <<((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }

    cout << "Radix Sort time:\n";
    for (int i = 0; i < M; ++i)
    {
        randomVector(vec);
        auto chrono_start = steady_clock::now();
        radixSort(vec);
        auto chrono_end = steady_clock::now();
        cout << ((duration<double>)(chrono_end - chrono_start)).count() << '\n';
    }


    return 0;
}


void randomVector(vector<int> & vec)
{
    seed_seq seed;
    mt19937 mt(seed);

    uniform_int_distribution<int> dist(INT_MIN, INT_MAX);
    for (int & i : vec)
    {
        i = dist(mt);
    }
}


void radixSort(vector<int> & vec)
{
    int n = (int)vec.size();
    int count[10];
    int* temp = new int[n];
    int max = 0;

    for (int & i : vec)
    {
        if (i > max)
        {
            max = i;
        }
    }
    int maxdigits = (int)to_string(max).length();

    for (int digit = 0; digit < maxdigits; digit++)
    {
        for (int & i : vec)
        {
            int t = (int)pow(10, digit);
            count[(i % (10 * t)) / t]++;
        }
        int k = 0;
        for (int p = 0; p < 10; ++p)
        {
            for (int & i : vec)
            {
                int t = (int)pow(10, digit);
                if ((i % (10 * t)) / t == p)
                {
                    temp[k] = i;
                    k++;
                }
            }
        }
        memset(count, 0, sizeof(count));
        for (int i = 0; i < n; ++i)
        {
            vec[i] = temp[i];
        }
    }
    delete[] temp;
}


void shakerSort(vector<int> & vec)
{
    int size = (int)vec.size() - 1;
    int left  = 0;
    int right = (int)vec.size() - 1;
    do
    {
        for (int i = left; i < right; ++i)
        {
            if (vec[i] > vec[i + 1])
            {
                swap(vec[i], vec[i + 1]);
                size = i;
            }
        }
        right = size;
        for (int i = right; i > left; --i)
        {
            if (vec[i] < vec[i - 1])
            {
                swap(vec[i], vec[i - 1]);
                size = i;
            }
        }
        left = size;
    } while (left < right);
}


void bubbleSort(vector<int> & vec, int start)
{
    if (start == INT_MIN){
        start = 1;
    }
    int size = (int)vec.size() - 1;

    auto f = [](vector<int> & vec, int start, int size)
    {
        for (int i = size; i > start; i--)
        {
            int count = 0;
            for (int j = 1; j < i; j++) {
                if (vec[j] < vec[j - 1])
                    swap(vec[j], vec[j - 1]);
                count++;
            }
            if (!count)
                return;
        }
    };
    f(vec, start, size);
}


void MixedSort(vector<int> & vec, int start, int end)
{
    if (start == INT_MIN && end == INT_MAX)
    {
        start = 0;
        end = (int)vec.size() - 1;
    }
    if (end - start <= 100)
    {
        bubbleSort(vec);
    }
    else
    {
        int left = start, right = end;
        if (left >= right) return;
        int S = vec[(left + right) / 2];
        while (left <= right)
        {
            while (vec[left] < S) left++;
            while (vec[right] > S) right--;
            if (left <= right)
            {
                swap(vec[left], vec[right]);
                left++; right--;
            }
        }
        quickSort(vec, start, right);
        quickSort(vec, left, end);
    }
}


void mergeSort(vector<int> & vec, int start, int end)
{
    if (start == INT_MIN && end == INT_MAX)
    {
        start = 0;
        end = (int)vec.size() - 1;
    }
    if (end - start < 1) return;
    if (end - start == 1) {
        if (vec[start] > vec[start+1])
        {
            swap (vec[start], vec[start+1]);
        }
        return;
    }
    mergeSort (vec, start, start + (end - start) / 2);
    mergeSort (vec, start + (end - start) / 2, end);
    int*  mass_sort = new int [end];
    int count = 0;
    int l1 = start;
    int l2 = start + (end - start) / 2;
    int l3 = l2;
    while (count < end - start)
    {
        if (((l3 < end) && (vec[l1] >= vec[l3])) || (l1 >= l2))
        {
            mass_sort[count] = vec[l3];
            l3++;
            count++;
        }
        else {
            mass_sort[count] = vec[l1];
            l1++;
            count++;
        }
    }
    for (int i = start; i < end; i++)
    {
        vec[i] = mass_sort[i - start];
    }
}


void quickSort(vector<int> & vec, int start, int end)
{
    if (start == INT_MIN && end == INT_MAX)
    {
        start = 0;
        end = (int)vec.size() - 1;
    }
    int left = start, right = end;
    if (left >= right) return;
    int S = vec[(left + right) / 2];
    while (left <= right)
    {
        while (vec[left] < S) left++;
        while (vec[right] > S) right--;
        if (left <= right)
        {
            swap(vec[left], vec[right]);
            left++; right--;
        }
    }
    quickSort(vec, start, right);
    quickSort(vec, left, end);
}


void insertSort(vector<int> & vec)
{
    int size = (int)vec.size();
    int min, max;
    for (int i = 0; i < size / 2 + 1; i++)
    {
        min = i; max = size - 1 - i;
        for (int j = i; j < size - (i != 0 ? i : 1); j++)
        {
            min = vec[j] < vec[min] ? j : min;
            max = vec[j] > vec[max] ? j : max;
        }
        if (i != min) swap(vec[i], vec[min]);
        if (size - 1 - i != max) swap( vec[size - 1 - i], vec[max]);
    }
}
/*
⣿⣿⣿⣿⡟⠛⠁⠄⠄⠄⠄⢀⣀⣀⠄⠄⠄⠄⣤⣽⣿⣿⣿⣿⣿⣿⣿⣿
⣿⣿⣿⡋⠁⠄⠄⠄⣠⣶⣾⣿⣿⣿⣿⠄⢦⡄⠐⠬⠛⢿⣿⣿⣿⣿⣿⣿
⣿⡿⠇⠁⠄⠄⣠⣾⣿⣿⡿⠟⠋⠁⠄⠄⠈⠁⠄⠄⠄⠄⠙⢿⣿⣿⣿⣿
⣿⠃⠄⠄⠄⠘⣿⣿⣿⣿⢀⣠⠄⠄⠄⠄⣰⣶⣀⠄⠄⠄⠄⠸⣿⣿⣿⣿
⣏⠄⠄⠄⠄⠄⣿⣿⣿⡿⢟⣁⠄⣀⣠⣴⣿⣿⠿⠷⠶⠒⠄⠄⢹⣿⣿⣿
⡏⠄⠄⠄⠄⢰⣿⣿⣿⣿⣿⣿⣿⣿⡟⠄⠛⠁⠄⠄⠄⠄⠄⠄⢠⣿⣿⣿
⡇⠄⠄⠄⠄⠈⢿⣿⣿⣿⣿⣿⣿⣿⡇⠄⣼⣿⠇⠘⠄⠁⠄⠄⠄⢻⣿⣿
⣇⠄⠄⠄⠄⠄⠸⢿⣿⣿⣿⣿⣿⣿⠁⠸⠟⠁⣠⣤⣤⣶⣤⠄⠄⠄⢻⣿
⣿⡄⠄⡤⢤⣤⡀⠈⣿⣿⣿⣿⣿⣿⡆⠄⠄⠘⠋⠁⠄⠄⠈⠄⠄⠄⢸⣿
⣿⣿⡜⢰⡾⢻⣧⣰⣿⣿⣿⣿⣿⣿⣷⠄⣼⣷⣶⣶⡆⠄⠄⠄⠄⠄⠄⣿
⣿⣿⣧⢸⠄⣼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⣿
⣿⣿⣿⣿⡿⢿⡟⠉⢻⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⠄⠄⢀⡀⠄⠘⣿
⣿⣿⣿⣿⣿⣆⢻⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠟⠋⠄⠄⠈⠁⠄⠄⣿
⣿⣿⣿⣿⣿⣿⡆⢻⣿⣿⣿⣿⣿⣿⡿⠛⠛⠛⠃⠄⠄⠄⠄⠄⠄⠄⢀⣿
⣿⣿⣿⣿⣿⣿⣿⣆⣻⣿⣿⣿⣿⣿⣷⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⢸⣿
 */
