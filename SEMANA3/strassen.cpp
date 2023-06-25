#include <iostream>
#include <vector>

// Función auxiliar para sumar dos matrices
std::vector<std::vector<int>> matrixAddition(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    return result;
}

// Función auxiliar para restar dos matrices
std::vector<std::vector<int>> matrixSubtraction(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            result[i][j] = A[i][j] - B[i][j];
        }
    }

    return result;
}

// Función para multiplicar matrices usando el algoritmo de Strassen
std::vector<std::vector<int>> strassenMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int n = A.size();

    // Caso base: matrices de tamaño 1x1
    if (n == 1) {
        return {{A[0][0] * B[0][0]}};
    }

    // División de las matrices en submatrices
    int halfSize = n / 2;
    std::vector<std::vector<int>> A11(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> A12(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> A21(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> A22(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B11(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B12(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B21(halfSize, std::vector<int>(halfSize));
    std::vector<std::vector<int>> B22(halfSize, std::vector<int>(halfSize));

    // Llenar las submatrices
    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + halfSize];
            A21[i][j] = A[i + halfSize][j];
            A22[i][j] = A[i + halfSize][j + halfSize];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + halfSize];
            B21[i][j] = B[i + halfSize][j];
            B22[i][j] = B[i + halfSize][j + halfSize];
        }
    }

      // Calcula los productos recursivamente

    std::vector<std::vector<int>> P = strassenMultiply(matrixAddition(A11, A22), matrixAddition(B11, B22));
    std::vector<std::vector<int>> Q = strassenMultiply(matrixAddition(A21, A22), B11);
    std::vector<std::vector<int>> R = strassenMultiply(A11, matrixSubtraction(B12, B22));
    std::vector<std::vector<int>> S = strassenMultiply(A22, matrixSubtraction(B21, B11));
    std::vector<std::vector<int>> T = strassenMultiply(matrixAddition(A11, A12), B22);
    std::vector<std::vector<int>> U = strassenMultiply(matrixSubtraction(A11, A21), matrixAddition(B11, B12));
    std::vector<std::vector<int>> V = strassenMultiply(matrixSubtraction(A12, A22), matrixAddition(B21, B22));
    
    

    // Calcula las submatrices del resultado
    std::vector<std::vector<int>> C11 = matrixAddition(matrixSubtraction(matrixAddition(P, S), T), V);
    std::vector<std::vector<int>> C12 = matrixAddition(R, T);
    std::vector<std::vector<int>> C21 = matrixAddition(Q, S);
    std::vector<std::vector<int>> C22 = matrixSubtraction(matrixSubtraction(matrixAddition(P, R), Q), U);


    // Combina las submatrices para obtener el resultado final
    std::vector<std::vector<int>> result(n, std::vector<int>(n, 0));
    for (int i = 0; i < halfSize; ++i) {
        for (int j = 0; j < halfSize; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + halfSize] = C12[i][j];
            result[i + halfSize][j] = C21[i][j];
            result[i + halfSize][j + halfSize] = C22[i][j];
        }
    }

    return result;
}

// Función auxiliar para imprimir una matriz
void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int element : row) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> A = {{1, 2, 3, 4}, {3, 4, 5, 1}, {3, 4, 2, 3}, {3, 4, 1, 1}};
    std::vector<std::vector<int>> B = {{5, 6, 6, 6}, {7, 8, 12, 7}, {3, 2, 1, 1}, {3, 1, 5, 7}};

    std::cout << "Matriz A:" << std::endl;
    printMatrix(A);

    std::cout << "Matriz B:" << std::endl;
    printMatrix(B);

    std::cout << "Resultado de la multiplicación:" << std::endl;
    std::vector<std::vector<int>> result = strassenMultiply(A, B);
    printMatrix(result);

    return 0;
}
