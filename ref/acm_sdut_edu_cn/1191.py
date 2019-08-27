data = list(input())

print(len(data))

for num in range(len(data)-1):
    print(int(data[num]), end=' ')
print(data[len(data)-1])

for num in range(len(data)-1):
    print(int(data[len(data)-1-num]), end=' ')
print(data[0])

