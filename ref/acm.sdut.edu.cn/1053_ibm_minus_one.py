case = int(input())

for num in range(case):

    string = input()
    successor = ''
    for char in string:
        if(ord(char)==90):
            successor += chr(ord(char)-25)
        else:
            successor += chr(ord(char)+1)

    print('String #' + str(num+1))
    print(successor)
    print()
