/// в оптимизированном решении вместо третьей координаты Z
/// хранится сумма значений всех элементов до текущего + текущий, что позволяет
/// вместо добавления за 1 и суммирования за 100^3 операций в худшем случае получить
/// добавление за 100 и и суммирование за 100^2 в худшем случае

#include<fstream>

using namespace std;

#define MAX 101 // максимальный размер каждого измерения - 100 (+1 чтобы не смещать индексы)
#define TYPE int64_t // тип данных ячейки трёхмерного массива

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    TYPE n;
    TYPE ***array;

    array = new TYPE** [MAX];
    for (int i = 0; i < MAX; ++i)
    {
        array[i] = new TYPE* [MAX];
        for (int j = 0; j < MAX; ++j)
            array[i][j] = new TYPE [MAX]{0};
    }

    fin >> n;

    for (int i = 0; i < n; ++i)
    {
        TYPE type;
        fin >> type;

        switch (type)
        {
        case 1:
            {
            short x, y, z;
            TYPE value;
            fin >> x >> y >> z >> value;
            int64_t diff = value - (array[x][y][z] - array[x][y][z - 1]);
            for (short Z = z; Z < MAX; ++Z)
                array[x][y][Z] += diff;
            }
            break;

        case 2:
            {
            short x0, y0, z0, x1, y1, z1;
            TYPE sum = 0;
            fin >> x0 >> y0 >> z0 >> x1 >> y1 >> z1;
            if (x0 > x1) swap(x0, x1);
            if (y0 > y1) swap(y0, y1);
            if (z0 > z1) swap(z0, z1);
            for (short x = x0; x <= x1; ++x)
                for (short y = y0; y <= y1; ++y)
                    sum += array[x][y][z1] - array[x][y][z0 - 1];

            fout << sum << '\n';
            }
            break;

        default:
            break;
        }
    }

    fin.close();
    fout.close();
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