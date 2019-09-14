d = input()
for num in range(int(d)):
    decimal = int(input())
    bits = []
    while(decimal//2):
        bits.append(decimal%2)
        decimal //= 2
    bits.append(decimal%2)
    for location, value in enumerate(bits):
        if value == 1:
            print(location, end=' ')
    print()


