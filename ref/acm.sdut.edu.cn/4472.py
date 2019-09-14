def bigger(first, second):
    bigger = ''
    length = 0
    if(len(first) > len(second)):
        length = len(second)
        bigger = first
    else:
        length = len(first)
        bigger = second

    for num in range(length):
        if(ord(first[num]) > ord(second[num])):
            bigger = first
            break
        elif(ord(first[num]) < ord(second[num])):
            bigger = second
            break
        else:
            pass

    return(bigger)


data = []
first = ''
second = ''
third = ''
for num in range(3):
    data.append(input())

first = bigger(data[0], data[1])
second = bigger(data[1], data[2])
first = bigger(first, second)

data.remove(data[data.index(first)])
second = bigger(data[0], data[1])

data.remove(data[data.index(second)])
third = data[0]

print(first)
print(second)
print(third)
