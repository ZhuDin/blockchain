number = int(input())
data = input().split()

for num in range(number):
    data[num] = int(data[num])

temp = 0
index = 0

temp = max(data)
index = data.index(temp)
data[index] = data[-1]
data[-1] = temp

temp = min(data)
index = data.index(temp)
data[index] = data[0]
data[0] = temp

for num in range(number):
    data[num] = str(data[num])

print(' '.join(data))

