def min_positive(numbers):
    return min(list(filter(lambda x: x > 0, numbers)))

def main():
    inp = [int(x) for x in input().split()]
    print(min_positive(inp))

main()