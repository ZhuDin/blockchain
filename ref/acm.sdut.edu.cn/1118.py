data = input().split()

numbers = []
for num in data:
    numbers.append(int(num))

numbers.sort(reverse=True)
for num in numbers:
    print(num, end=' ')

print()
