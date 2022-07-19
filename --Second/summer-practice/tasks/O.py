def main():
    n = int(input())
    files = {}
    for i in range(n):
        name, *op = input().split()
        files[name] = op
    
    m = int(input())
    for j in range(m):
        o, file = input().split()
        o = o.replace('read', 'R').replace('write', 'W').replace('execute', 'X')
        if o in files[file]:
            print('OK')
        else:
            print('Access denied')


main()
