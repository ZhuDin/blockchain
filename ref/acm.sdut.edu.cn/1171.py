data = list(input())

label = 0
for num in data:
    if ord(num) <= ord('9') and ord(num) >= ord('0') :
        label += 1
        continue
    else:
        data[label] = '*'
    label += 1

result = ''
for num in range(len(data)-1):
    if data[num] == '*' and data[num+1] == '*':
        continue
    else:
        result += data[num]

result += data[-1]

print(result)

