data = input().split()

x = int(data[0])
y = int(data[1])

def lcm(x, y):
    while(y != 0):
        temp = x % y
        x = y
        y = temp
    return x

print(int(x*y/lcm(x, y)), end=' ')
print(lcm(x,y))

