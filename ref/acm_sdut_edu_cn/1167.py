data = input().split()

a = float(data[0])
b = float(data[1])
c = float(data[2])

print(int(a+b+c), end=' ')
print(int(a*b*c), end=' ')
print('{:0.2f}'.format((a+b+c)/3))

