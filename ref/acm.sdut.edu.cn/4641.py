num = input().split()

n = int(num[0])
m = int(num[1])

numbers = input().split()

array = []

for a in range(m):
    array.append(input().split())

integers = input().split()

l = int(integers[0])
r = int(integers[1])

print("%d %d" % (n,m))
print(numbers)
for a in range(m):
    print(array[a])
print(integers)