data = input().split()

row = int(data[0])
col = int(data[1])

matrix = []
for r in range(row):
    data = input().split()
    matrix.append([])
    for c in range(col):
        matrix[r].append(int(data[c]))

matrix_transpose = list(zip(*matrix))
location_row = 0
location_col = 0
value = 0
flag = 0
for r in range(row):
    location_row = r
    location_col = matrix[r].index(max(matrix[r]))
    if(min(matrix_transpose[location_col]) == max(matrix[r])):
        value = matrix[r][location_col]
        flag = 1
        break
        
if(flag == 0):
    print('None')
else:
    print('Array[' + str(location_row) + '][' + \
            str(location_col) + ']=' + str(value))
