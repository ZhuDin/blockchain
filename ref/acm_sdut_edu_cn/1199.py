import math

data = input().split()

x = int(data[0])
n = int(data[1])

for num in range(n):
    x += num + 1
    x = math.sqrt(x)

print('{:.2f}'.format(x))
