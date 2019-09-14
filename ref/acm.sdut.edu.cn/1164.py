number = int(input())

matrix = []

for num in range(number):
    matrix.append(input().split())

for row in range(number):
    for col in range(row):
        temp = matrix[row][col]
        matrix[row][col] = matrix[col][row]
        matrix[col][row] = temp

for row in range(number):
    print(' '.join(matrix[row]))
    
