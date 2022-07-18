from math import *


def is_prime(x):
    return sum(filter(lambda y: x % y == 0, [y for y in range(1, int(sqrt(x)) + 1)])) == 1


def is_palindrome(x):
    return str(x) == ''.join(reversed(str(x)))


def is_degree_two(x):
    return x & (x - 1) == 0 and x != 0


def check_pin(str):
    pars_num = list(map(lambda x: int(x), str.split('-')))
    return is_prime(pars_num[0]) and is_palindrome(pars_num[1]) and is_degree_two(pars_num[2])


def main():
    value = '1-101-16'
    if check_pin(value):
        print('Корректен')
    else:
        print('Некорректен')


main()