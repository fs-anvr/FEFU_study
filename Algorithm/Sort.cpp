#include <iostream>
#include <fstream>
#include <ctime>
#include <chrono>
using namespace std;

void bubble_sort (int* mass, int size)
{
    for (int i = size; i > 1; i--)
    {
        for (int j = 1; j < i; j++)
        {
            if (mass[j] < mass[j - 1])
                swap (mass[j], mass[j-1]);
        }
    }
}

void insert_sort (int* mass, int size)
{
    int min, max;
    for (int i = 0; i < size / 2 + 1; i++)
    {
        min = i; max = size - 1 - i;
        for (int j = i; j < size - (i != 0 ? i : 1); j++)
        {
            min = mass[j] < mass[min] ? j : min;
            max = mass[j] > mass[max] ? j : max;
        }
        if (i != min) swap(mass[i], mass[min]);
        if (size - 1 - i != max) swap( mass[size - 1 - i], mass[max]);
    }
}

void quick_sort (int* mass, int start, int end)
{
    int left = start, right = end;
    if (left >= right) return;
    int S = mass[(left + right) / 2];
    while (left <= right)
    {
        while (mass[left] < S) left++;
        while (mass[right] > S) right--;
        if (left <= right)
        {
            swap(mass[left], mass[right]);
            left++; right--;
        }
    }
    quick_sort(mass, start, right);
    quick_sort(mass, left, end);
}

void merge_sort (int* mass, int start, int end) {
    if (end - start < 1) return;
    if (end - start == 1) {
        if (mass[start] > mass[start+1]) {
            //inv ++;
            swap (mass[start], mass[start+1]);
        }
        return;
    }
    merge_sort (mass, start, start + (end - start) / 2);
    merge_sort (mass, start + (end - start) / 2, end);
    int*  mass_sort = new int [end];
    int count = 0;
    int l1 = start;
    int l2 = start + (end - start) / 2;
    int l3 = l2;
    while (count < end - start) {
        if (((l3 < end) && (mass[l1] >= mass[l3]))) {
            mass_sort[count] = mass[l3];
            l3++;
            count++;
        }
        else if (l1 >= l2) {
            mass_sort[count] = mass[l3];
            l3++;
            count++;
        }
        else {
            //inv += l3 - l2;
            mass_sort[count] = mass[l1];
            l1++;
            count++;
        }
    }
    for (int i = start; i < end; i++) {
        mass[i] = mass_sort[i - start];
    }
}

int main() {
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int n, cur;
    in >> n;
    int* mass0 = new int [n];
    int* mass1 = new int [n];
    int* mass2 = new int [n];
    int* mass3 = new int [n];
    for (int i = 0; i < n; i++)
    {
        in >> cur;
        mass0[i] = mass1[i] = mass2[i] = mass3[i] = cur;
    }
    /*for (int i = 0; i < n; i++)
    {
        out << mass0[i] << " ";
    }
    out << "\n\n";*/

    auto start1 = std::chrono::steady_clock::now();
    bubble_sort (mass0, n);
    auto end1 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds1 = end1-start1;
    std::cout << "elapsed time: " << elapsed_seconds1.count() << "s\n";

    auto start2 = std::chrono::steady_clock::now();
    insert_sort (mass1, n);
    auto end2 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds2 = end2-start2;
    std::cout << "elapsed time: " << elapsed_seconds2.count() << "s\n";

    auto start3 = std::chrono::steady_clock::now();
    quick_sort (mass2, 0, n-1);
    auto end3 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds3 = end3-start3;
    std::cout << "elapsed time: " << elapsed_seconds3.count() << "s\n";

    auto start4 = std::chrono::steady_clock::now();
    merge_sort(mass3, 0, n-1);
    auto end4 = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsed_seconds4 = end4-start4;
    std::cout << "elapsed time: " << elapsed_seconds4.count() << "s\n";

    /*for (int i = 0; i < n; i++)
    {
        out << mass0[i] << " ";
    }
    out << "\n";

    for (int i = 0; i < n; i++)
    {
        out << mass1[i] << " ";
    }
    out << "\n";

    for (int i = 0; i < n; i++)
    {
        out << mass2[i] << " ";
    }
    out << "\n";

    for (int i = 0; i < n; i++)
    {
        out << mass3[i] << " ";
    }*/
    return 0;
}
