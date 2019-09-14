import time

before = input().split(':')
after = input().split(':')

bef = int(before[2]) + int(before[1])*60 + int(before[0])*3600
aft = int(after[2]) + int(after[1])*60 + int(after[0])*3600

print('{:0>2d}'.format(int(abs(bef-aft)/3600)), end=':')
print('{:0>2d}'.format(int(abs(bef-aft)%3600/60)), end=':')
print('{:0>2d}'.format(int(abs(bef-aft)%3600%60)))

