import math

data = input().split()

a = float(data[0])
b = float(data[1])
c = float(data[2])
if b**2-4*a*c > 0 :
    print('{:0.2f}'.format((-b+math.sqrt(b**2-4*a*c))/(2*a)), end=' ')
    print('{:0.2f}'.format((-b-math.sqrt(b**2-4*a*c))/(2*a)))
else:
    print('{:0.2f}'.format((-b)/(2*a)))

