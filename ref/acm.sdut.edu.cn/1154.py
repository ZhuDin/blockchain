data = list(input().split(','))

label = 0
for num in data:
    data[label] = int(num)
    label += 1

print('max=', end='')
print(max(data))

