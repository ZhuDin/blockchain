import math

while(1):
    data = input().split()
    if(data.count('0') == 6):
        break

    dictionary = {1:0, 2:0, 3:0, 4:0, 5:0, 6:0}
    number = 0  

    temp = 1
    for num in data:
        dictionary[temp] = int(num)
        temp += 1

    # 6*6
    number += dictionary[6]
    dictionary[6] = 0
    #print('#6:', end=' ')
    #print(dictionary, end='')
    #print(' --- ', str(number))
    
    # 5*5
    number += dictionary[5]
    if(dictionary[1]-11*dictionary[5] > 0):
        dictionary[1] -= 11*dictionary[5]
    else:
        dictionary[1] = 0
    dictionary[5] = 0
    #print('#5:', end=' ')
    #print(dictionary, end='')
    #print(' --- ', str(number))
    
    # 4*4
    number += dictionary[4]
    free = 20 * dictionary[4]
    square_one = dictionary[1]
    square_two = dictionary[2] * 4
    if(square_two - free > 0):
        dictionary[2] -= int(free/4)
        free = 0
    else:
        dictionary[2] = 0
        free -= square_two
    if(square_one - free > 0):
        dictionary[1] -= free
    else:
        dictionary[1] = 0
    dictionary[4] = 0
    #print('#4:', end=' ')
    #print(dictionary, end='')
    #print(' --- ', str(number))
    
    # 3*3
    number += math.ceil(dictionary[3]/4)
    free = math.ceil(dictionary[3]/4)*36 - dictionary[3]*9
    square_one = dictionary[1]
    square_two = dictionary[2] * 4
    if(free == 27):
        # 20 7
        if(square_two > 20):
            dictionary[2] -= 5
            free -= 20
        else:
            dictionary[2] = 0
            free -= square_two
        if(square_one > free):
            dictionary[1] -= free
        else:
            dictionary[1] = 0
    if(free == 18):
        # 12 6
        if(square_two > 12):
            dictionary[2] -= 3
            free -= 12  
        else:
            dictionary[2] = 0
            free -= square_two
        if(square_one > free):
            dictionary[1] -= free
        else:
            dictionary[1] = 0
    if(free == 9):
        # 4 5
        if(square_two > 4):
            dictionary[2] -= 1
            free -= 4
        else:
            dictionary[2] = 0
            free -= square_two
        if(square_one > free):
            dictionary[1] -= free
        else:
            dictionary[1] = 0  
    dictionary[3] = 0
    #print('#3:', end=' ')
    #print(dictionary, end='')
    #print(' --- ', str(number))

    # 2*2
    number += math.ceil(dictionary[2]/9)
    free = math.ceil(dictionary[2]/9)*36 - dictionary[2]*4
    square_one = dictionary[1]
    dictionary[2] = 0
    if(dictionary[1] > free):
        dictionary[1] -= free
    else:
        dictionary[1] = 0
    #print('#2:', end=' ')
    #print(dictionary, end='')
    #print(' --- ', str(number))
    
    # 1*1
    number += math.ceil(dictionary[1]/36)
    #print('#1:', end=' ')
    #print(dictionary, end='')
    #print(' --- ', str(number))

    print(number)
