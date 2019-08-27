int_n = int(input())

for num in range(int_n):
    int_m = input().split()
    total = 0
    for mem in range(int(int_m[0])):
        total += int(int_m[mem+1])
    print(total)
    print()

