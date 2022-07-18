def in_field(x, y, n, m):
    return 0 <= x < m and 0 <= y < n

def mining(field, mines, n, m):
    new_field = field.copy()
    for x, y in mines:
        new_field[x][y] = '*'
        for dx in range(-1, 2):
            c_x = x + dx
            for dy in range(-1, 2):
                c_y = y + dy
                if in_field(c_y, c_x, n, m) and new_field[c_x][c_y] != '*':
                    new_field[c_x][c_y] += 1
    return new_field

def main():
    n, m, k = map(int, input().split())
    field = [[0 for i in range(m)] for j in range(n)]
    mines = []
    for i in range(k):
        x, y = map(lambda x: int(x) - 1, input().split())
        mines.append([x, y])
    mined_field = mining(field, mines, n, m)
    for i in range(n):
        print (*mined_field[i])


main()