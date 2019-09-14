data = []

for num in range(2):
    data.append(input())

bigger = ''
length = 0
if(len(data[0]) > len(data[1])):
    length = len(data[1])
    bigger = data[0]
else:
    length = len(data[0])
    bigger = data[1]

for num in range(length):
    if(ord(data[0][num]) > ord(data[1][num])):
        bigger = data[0]
        break
    elif(ord(data[0][num]) < ord(data[1][num])):
        bigger = data[1]
        break
    else:
        pass

print(bigger)
