data = input()

char = 'a'
number = 0

for num in range(ord('a'), ord('z')):
    temp = data.count(chr(num))
    if(temp > number):
        number = temp
        char = chr(num)

print(char)
