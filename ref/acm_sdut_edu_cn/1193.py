number = int(input())

pi = 0.0

for num in range(0,2*number):
    pi += (-1)**num / (2*num+1)

print('{:.5f}'.format(pi*4))

