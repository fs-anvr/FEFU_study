def gematria(word):
    return sum(map(lambda c: (ord(c) - ord('A') + 1), word))


def main():

    print('Введите количество слов: ', end='')
    lines_no = int(input())

    words = []
    print('Введите слова:')
    for i in range(lines_no):
        words.append(input())

    print('Слова, отсортированные по гематрии:')
    print(*sorted(sorted(words), key=lambda word: (gematria(word.upper()))))


main()