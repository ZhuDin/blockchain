data = input().split()

for num in range(len(data)):
    data[num] = int(data[num])

sort = sorted(data)
for num in range(len(sort)):
    sort[num] = str(sort[num])

print(' '.join(sort))

for num in range(len(sort)):
    print(data.index(int(sort[num]))+1, end=' ')
print()


