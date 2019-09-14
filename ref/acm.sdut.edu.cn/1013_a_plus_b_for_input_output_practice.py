sum = input().split()

while(1):
    if(int(sum[0]) == 0):
        break
    else:
        total = 0
        for num in range(int(sum[0])):
            total += int(sum[num+1])
        print(total)
    sum = input().split()
