number = int(input())

for n in range(0, number):
    print(' ' * (number-n), end='')
    print('*', end='')
    print(' ' * n, end='')
    print('*')
    print()