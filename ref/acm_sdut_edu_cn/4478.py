# a e i o u

data = input()

for char in data:
    if(char=='a' or char=='e' or char=='i' or char=='o' or char=='u'):
        continue
    else:
        data = data.replace(str(char),'',1)

print(data)

