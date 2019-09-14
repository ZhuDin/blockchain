data = input().split()

mark = int(input())

result = []

number = int(data[0])

result += data[number-mark+1:]

result += data[1:number-mark+1]

print(' '.join(result))

