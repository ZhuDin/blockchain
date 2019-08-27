num = int(input())

while(1):
    if(num == 0):
        break
    bits = []
    while(num//2):
        bits.append(num%2)
        num //= 2
    bits.append(num%2)
    bit = 0
    weight = 1
    for element in bits:
        if element == 1:
            bit += weight 
            break
        else:
            weight *= 2
    print(bit)
    num = int(input())
