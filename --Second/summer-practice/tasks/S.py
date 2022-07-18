def main():
    n = int(input())
    lat_eng_dict = {}
    for i in range(n):
        eng, lat = input().split(' - ')
        lat = (lat.split(', '))
        for l in lat:
            try:
                lat_eng_dict[l].append(eng)
            except KeyError:
                lat_eng_dict[l] = [eng]

    print(len(lat_eng_dict.keys()))
    for lat in sorted(lat_eng_dict.keys(), key=lambda x: x):
        print(lat, end=' - ')
        print(lat_eng_dict[lat][0], end='')
        for i in range(1, len(lat_eng_dict[lat])):
            print(f', {lat_eng_dict[lat][i]}', end='')
        print()

main()