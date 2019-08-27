integer_n = int(input())

while(integer_n):
    integer_n -= 1
    member = input().split()
    sum_integer = 0
    for mem in range(int(member[0])):
        sum_integer += int(member[mem+1])
    print(sum_integer)
