import math

number = int(input())

def is_prime(number):
    num = int(number)
    if(num==1):
        return False
    if(num<=3 and num>1):
        return True

    sqrt = int(math.sqrt(num))
    for temp in range(2, sqrt+1):
        if(num%temp == 0):
            return False

    return True

if(is_prime(number)):
    print('This is a prime.')
else:
    print('This is not a prime.')
