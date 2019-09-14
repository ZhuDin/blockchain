data = list(input())

label = 0
for char in data:
    if ord(char) <= ord('Z') and ord(char) >= ord('A'):
        data[label] = chr(ord(char)+32)
        label += 1
    elif ord(char) <= ord('z') and ord(char) >= ord('a'):
        data[label] = chr(ord(char)-32)
        label += 1
    else:
        label += 1

print(''.join(data))

