def number_even(x):
    return len([y for y in str(x) if int(y) % 2 == 0])

def main():
    x = int(input())
    print(number_even(x))


main()