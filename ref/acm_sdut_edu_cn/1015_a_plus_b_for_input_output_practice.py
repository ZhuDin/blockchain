member = input().split()

while(1):
    total = 0
    for num in range(int(member[0])):
        total += int(member[num+1])

    print(total)
    member = input().split()

