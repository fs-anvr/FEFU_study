def main():
    print(sum(map(lambda x: x*x, filter(lambda x: x % 9 == 0, range(10, 100)))))


main()