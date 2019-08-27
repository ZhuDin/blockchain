data = list(input())
result = ''

for char in data:
    if ord(char) <= ord('z') and ord(char) >= ord('a'): 
        result += char
    if ord(char) <= ord('Z') and ord(char) >= ord('A'):
        result += char

print(result)

