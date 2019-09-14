data = input().split()

for num in range(len(data)):
    data[num] = int(data[num])

data.remove(max(data))
data.remove(min(data))

print(data[0])

