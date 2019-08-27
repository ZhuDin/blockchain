time = input()

for num in range(int(time)):
    numbers = input().split()
    x = int(numbers[0])
    y = int(numbers[1])
    
    #row 0 or col 0
    if(x==0 and y==0):
        print(0)
    elif(x==2 and y==0):
        print(2)
    elif(x==0 or y==0):
        print('No Number')
    #row 1 or col 1
    elif(x==1 and y==1):
        print(1)
    elif(x==3 and y==1):
        print(3)
    elif(x==1 or y==1):
        print('No Number')
    #row 2*N or col 2*N
    elif(x/2==y/2 and x%2==0):
        print(x*2)
    elif((x-2)/2==y/2 and (x-2)%2==0):
        print((x-2)*2+2)
    # row 3*N or col 3*N
    elif(x/2==y/2 and x%2==1):
        print((x-1)*2+1)
    elif((x-2)/2==y/2 and (x-2)%2==1):
        print((x-3)*2+3)
    else:
        print('No Number')


