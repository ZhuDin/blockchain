average = 0.0

for month in range(12):
    average = average + float(input())

print('$' + str(round((average/12.0),2)))
