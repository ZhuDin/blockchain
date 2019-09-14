while(1):
    number = int(input())
    
    if(number == 0):
        break

    total = 0

    while(1):
        total += number % 10
        number //= 10
        
        if(number == 0 and total > 9):
            number = total
            total = 0
        if(number == 0 and total < 10):
            print(total)
            break
