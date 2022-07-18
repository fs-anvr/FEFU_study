def generate_list(k):
    l = [0, 0]
    for i in range(k-1):
        l = [l, l]
    return l


def main():
    k = int(input())
    print(generate_list(k))

main()
