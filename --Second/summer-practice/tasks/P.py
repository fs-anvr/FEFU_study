import sys

def main():
    dictionary = {}
    for line in sys.stdin:
        current_words = line.split()
        for word in current_words:
            if word in dictionary:
                dictionary[word] += 1
            else:
                dictionary[word] = 1
    words = dictionary.keys()
    numbers = dictionary.values()
    sorted_words = sorted(zip(numbers, words), key=lambda item: (-item[0], item[1]))
    for item in sorted_words:
        print(item[1])

    
main()