data = input().split()
integer = int(data[0])
system = int(data[1])

base = []
reminder = 0
while int(integer/system):
    reminder = int(integer%system)
    integer = int(integer/system)
    base.append(str(reminder))

reminder = integer % system
if reminder < system :
    base.append(str(reminder))
print(''.join(base[::-1])) 