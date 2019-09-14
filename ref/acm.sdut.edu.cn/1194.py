while(1):
    data = input().split()
    x = float(data[0])
    n = int(data[1])
    result = 0.0

    for num in range(0, n+1):
        fact = 1.0
        if num == 0:
            fact = 1
        for fac in range(1,num*2+1):
            fact *= fac
        
        if num == 0:
            result += 1
        elif(num%2 == 0):
            result += x**(2*num) / fact
        else:
            result += -1 * x**(2*num) / fact
            
    print('{:.4f}'.format(result))
