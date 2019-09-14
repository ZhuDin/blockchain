number = input()

for num in range(int(number)):
    length = int(input())

    for row in range(length):
        print((row+1)*'*', end='')
        print()

