number = int(input())

if(number == 0):
    print(1)
else:
    total = 1
    for num in range(1,number):
        total += num*total
    print(total)
