# TOD0: Create a function to find the matrix index with the best combined accuracy and precision
def best_performance(matrices):
    best_index = 0
    best_accuracy = 0
    best_precision = 0
    # TOD0: Define Loop through each matrix to calculate metrics
    for index, matrix in enumerate(matrices):
        # TOD0: Define tp, fp fn and tn
        tp = int(matrix[0])
        fp = int(matrix[1]) 
        fn = int(matrix[2])
        tn = int(matrix[3])
        
        # TODO: Calculate accuracy and precision
        accuracy = (tp + tn) / (tp + fp + fn + tn)
        precision = tp / (tp + fp)
        
        # TODO: Update best metrics if found
        if accuracy > best_accuracy and precision > best_precision:
           best_index = index + 1
           best_accuracy = accuracy
           best_precision = precision
           
    return best_index, round(best_accuracy,2), round(best_precision,2)

n = int(input())
matrices = []

for n in range(0, n):
    matrix = input()
    matrices.append(matrix.split(','))

# TOD0: Create a function to calculate accuracy and precision metrics
index, accuracy, precision = best_performance(matrices)

# Print the results
print(f'Índice: {index}')
print(f'Acurácia: {accuracy}')
print(f'Precisão: {precision}')