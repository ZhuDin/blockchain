number = int(input())

for num in range(number):
    data = input().split()
    hight = float(data[0])
    times = int(data[1])

    if times == 0:
        print('{:.2f}'.format(0), end=' ')
        print('{:.2f}'.format(hight/2.0))
        continue
    
    if times == 1:
        print('{:.2f}'.format(hight), end=' ')
        print('{:.2f}'.format(hight/2.0))
        continue

    distance = hight
    hight /= 2.0
    for h in range(times-1):
        distance += hight * 2.0
        hight /= 2.0
    print('{:.2f}'.format(distance), end=' ')
    print('{:.2f}'.format(hight))
