number = int(input())

for num in range(number):
    data = input().split()
    if(int(data[0]) > int(data[1])):
        print(data[0])
    else:
        print(data[1])

