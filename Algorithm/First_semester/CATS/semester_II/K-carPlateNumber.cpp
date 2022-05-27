#include <fstream>

using namespace std;

void copy(char *a, const char *b);
int function(char a[6][3]);

int main()
{
    ifstream fin ("numbers.in");
    ofstream fout ("numbers.out");


    char chars[6][3],numbers[6][3];
    fin >> chars[0][0] >> numbers[0][0] >> numbers[0][1] >> numbers[0][2] >> chars[0][1] >> chars[0][2];


    int sizeChars, sizeNumbers;
    sizeChars = function(chars);
    sizeNumbers = function(numbers);

    fout << sizeChars * sizeNumbers << '\n';
    for (int i = 0; i < sizeChars; ++i)
    {
        for (int j = 0; j < sizeNumbers; ++j)
        {
            fout << chars[i][0] << numbers[j][0] << numbers[j][1] << numbers[j][2] << chars[i][1] << chars[i][2] << '\n';
        }
    }


    fin.close();
    fout.close();

	return 0;
}


void copy(char *a, const char *b)
{
    a[0] = b[0];
    a[1] = b[1];
    a[2] = b[2];
}


int function(char a[6][3])
{
    for (int i = 1, t = 0;i < 6; ++i)
    {
        a[++t][0] = a[0][i%3];
        a[t][1+i/3] = a[0][(i+1)%3];
        a[t][2-i/3] = a[0][(i+2)%3];
    }

    int i = 1, j;
    int size = 6;

    while (i < size)
    {
        for (j = 0;j < i;j++)
        {
            if (a[i][0] == a[j][0] && a[i][1] == a[j][1] && a[i][2] == a[j][2])
            {
                j=-1;
                break;
            }
        }
        if (j == -1)
        {
            copy(a[i],a[--size]);
        }
        else
        {
            i++;
        }
    }

    return size;
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
