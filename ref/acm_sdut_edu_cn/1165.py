prime = [str(x) for x in range(100,200) if not [y for y in range(2,x) if x%y == 0]]

print(len(prime))
print(' '.join(prime))

