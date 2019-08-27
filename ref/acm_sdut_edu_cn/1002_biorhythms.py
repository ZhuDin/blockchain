count = 0

while(1):
    count += 1
    
    sample = input().split()
    p = int(sample[0])
    e = int(sample[1])
    i = int(sample[2])
    d = int(sample[3])

    answer = p
    
    if(p == -1 or e == -1 or i == -1 or d == -1):
        break

    answer = (5544*p + 14421*e + 1288*i -d + 21252)%21252
    if(answer == 0):
        answer = 21252 
    print('Case ' + str(count) + ': the next triple peak occurs in ' + str(answer) + ' days.')
