def my_map(function, values):
    return [function(x) for x in values]


def main():
    values = [1, 3, 1, 5, 7]
    operation = lambda x: x + 5
    print(*my_map(function=operation, values=values))


main()