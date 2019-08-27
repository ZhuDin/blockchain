data = input()

alpha = 0
for char in range(ord('a'), ord('z')):
    alpha += data.count(chr(char))
for char in range(ord('A'), ord('Z')):
    alpha += data.count(chr(char))

digit = 0
for num in range(10):
    digit += data.count(str(num))

space = data.count(' ')

other = len(data) - alpha - digit - space

print('English character:' + str(alpha))
print('digit character:' + str(digit))
print('space:' + str(space))
print('other character:' + str(other))

