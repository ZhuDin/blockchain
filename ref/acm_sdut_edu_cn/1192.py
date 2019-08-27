import math

data = input().split()
a = float(data[0])
b = float(data[1])
c = float(data[2])

delta = b*b - 4*a*c

if delta == 0:
    print('{:.2f}'.format((-b)/(2*a)), end=' ')
    print('{:.2f}'.format((-b)/(2*a)))
elif delta > 0.0:
    print('{:.2f}'.format(((-b)+math.sqrt(b*b-4*a*c))/2*a), end=' ')
    print('{:.2f}'.format(((-b)-math.sqrt(b*b-4*a*c))/2*a))
else:
    print('{:.2f}'.format((-b)/2*a), end='+')
    print('{:.2f}'.format(math.sqrt(4*a*c-b*b)/2*a), end='i')
    print(' ',end='')
    print('{:.2f}'.format((-b)/2*a), end='-')
    print('{:.2f}'.format(math.sqrt(4*a*c-b*b)/2*a), end='i')
    print()
