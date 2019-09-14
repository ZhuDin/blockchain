times = int(input())

for numbers in range(times):
    numbers = input().split()
    if(int(numbers[0]) >= int(numbers[1])):
        print('MMM BRAINS')
    else:
        print('NO BRAINS')

