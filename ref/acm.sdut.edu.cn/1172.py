number = int(input())
data = []

for num in range(number):
    data.append(input().split())

total = 0
for row in range(number):
    for col in range(number):
        if col == row+1:
            break
        total += int(data[row][col])

print(total)

