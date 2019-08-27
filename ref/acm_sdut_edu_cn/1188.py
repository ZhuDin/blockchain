while(1):
    data = input().split()
    if(int(data[0]) == 0):
        break

    number = []
    for num in range(1, int(data[0])+1):
        total = 0
        for char in range(len(data[num])):
            total += int(data[num][char]) 
        number.append(total)

    result = ''
    for num in sorted(number):
        result += data[number.index(num)+1] + ' '
    print(result.rstrip())

