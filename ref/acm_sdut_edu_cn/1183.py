data = input().split(',')

for num in range(len(data)):
    data[num] = int(data[num])

data.sort()

for num in range(len(data)):
    data[num] = str(data[num])

print(' '.join(data))

