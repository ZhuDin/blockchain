number = int(input())

print(' ' * (number-1)*2, end='')
print(1)

for num in range(1,number):
    print(' ' * (number-1-num)*2, end='')
    
    for col in range(num+1):
        print(col+1, end=' ')
    
    for col in range(num-1):
        print(num-col, end=' ')

    print(1)

