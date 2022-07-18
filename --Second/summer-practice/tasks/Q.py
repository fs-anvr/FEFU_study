def main():
    n = int(input())
    countries = {}
    for i in range(n):
        country, *cities = (input().split())
        for city in cities:
            countries[city] = country
    
    m = int(input())
    for j in range(m):
        city = input()
        print(countries[city])


main()
