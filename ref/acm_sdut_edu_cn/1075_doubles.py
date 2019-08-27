string = input().split()

while(1):
    if(int(string[0]) == -1):
        break
    total = 0
    for char in string[:-1]:
        if(str(int(char)*2) in string):
            total += 1
    print(total)
    string = input().split()

