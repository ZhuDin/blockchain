sum = input().split()

while(1):
    if(int(sum[0]) == 0 and int(sum[1]) == 0):
        break
    else:
        print(int(sum[0]) + int(sum[1]))

    sum = input().split()
