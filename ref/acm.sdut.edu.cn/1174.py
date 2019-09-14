number = int(input())

for num in range(number):
    print((number-num-1)*' ', end='')
    print((num+1)*'*', end='')
    print(num*'*', end='')
    print()

for num in range(1, number):
    print(num*' ', end='')
    print(((number-1-num)*2+1)*'*', end='')
    print()

