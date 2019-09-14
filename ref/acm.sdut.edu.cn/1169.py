number = int(input())

nume = 2
deno = 1
total = 0
for num in range(number):
    total += nume/deno
    temp = deno
    deno = nume
    nume += temp

print("{:0.6f}".format(total))

