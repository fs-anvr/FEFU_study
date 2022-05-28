#include <iostream>
#include <fstream>

long long InvCount = 0;
using namespace std;
void merge_sort (int* mass, int len);

int main()
{
    ifstream in ("input.txt");
    ofstream out ("output.txt");
    int n;
    in >> n;
    int *mass = new int [n];
    for (int i = 0; i < n; i++)
        in >> mass[i];
    merge_sort(mass, n);
    out << InvCount;

    in.close();
    out.close();
    return 0;
}

void merge_sort(int* mass, int len)
{
    if (len <= 1)
        return;

    int left_len = len / 2;
    int right_len = len - left_len;
    int *left = mass;
    int *right = mass + left_len;

    merge_sort(left, left_len);
    merge_sort(right, right_len);

    int i = 0, j = 0, index = 0;
    int *tmp_mass = new int[len];

    while (i < left_len || j < right_len)
    {
        if (j == right_len)
        {
            tmp_mass[index++] = left[i++];
        }
        else if (i == left_len)
        {
            tmp_mass[index++] = right[j++];
        }
        else if (left[i] <= right[j])
        {
            tmp_mass[index++] = left[i++];
        }
        else
        {
            tmp_mass[index++] = right[j++];
            InvCount += left_len - i;
        }
    }
    for (int i = 0; i < len; i++)
        mass[i] = tmp_mass[i];
}