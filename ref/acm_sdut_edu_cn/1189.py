data = list(input())

for num in range(len(data)):
    data[num] = int(data[num])

data = data[::-1]
number = data[:]

for num in range(len(data)):
    if(number[num] == 0):
        data.remove(0)
    else:
        break

for num in range(len(data)):
    print(data[num], end='')
print()

