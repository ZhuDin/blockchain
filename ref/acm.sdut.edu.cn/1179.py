number = int(input())

for num in range(number):
    print((number-num-1)*' ', end='')
    label = 0
    for n in range(num+1):
        label += 1
        print(label, end='')
    for n in range(num):
        label -= 1
        print(label, end='')
    print()

for num in range(number-1):
    print((num+1)*' ', end='')
    label = 0
    for n in range(number-num-1):
        label += 1
        print(label, end='')
    for n in range(number-num-2):
        label -= 1
        print(label, end='')
    print()

