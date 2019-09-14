number = int(input())

for num in range(number):
    data = int(input())
    odd = 1
    result = odd
    pos = 0
    while(result != data):
        result = odd
        temp = 0
        while(result < data):
            result *= 2
            temp += 1

        odd += 1
        pos = temp
    
    if(data==1):
        print('1 0')
    else:
        print(str(odd-1) + ' ' + str(pos))
