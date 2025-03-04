# store matrix input from file
file = 'Problem 81\matrix.txt'
matrix = []
with open(file, 'r') as file:
    for line in file:
        row = list(map(int, line.split(',')))
        matrix.append(row)

# initialize min_sum matrix, where min_sum[i][j] stores the minimum sum to reach bottom right cell from matrix[i][j]
min_sum = [[0 for i in range(len(matrix[0]))] for j in range(len(matrix))]

for i in range(len(matrix) - 1, -1, -1):
    for j in range(len(matrix[0]) - 1, -1, -1):
        min_sum[i][j] = matrix[i][j]
        if (i == len(matrix) - 1) and (j == len(matrix[0]) - 1):
            continue
        elif (i == len(matrix) - 1):
            min_sum[i][j] += min_sum[i][j + 1]
        elif (j == len(matrix[0]) - 1):
            min_sum[i][j] += min_sum[i + 1][j]
        else:
            min_sum[i][j] += min(min_sum[i + 1][j], min_sum[i][j + 1])

print(min_sum[0][0])