#include <iostream>
#include <vector>

void gaussJordan(std::vector<std::vector<double>>& matrix, int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (i != k) {
                double ratio = matrix[i][k] / matrix[k][k];
                for (int j = 0; j <= n; j++) {
                    matrix[i][j] -= ratio * matrix[k][j];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        double temp = matrix[i][i];
        for (int j = 0; j <= n; j++) {
            matrix[i][j] /= temp;
        }
    }
}

int main() {
    int n = 5;
    std::vector<std::vector<double>> matrix = { {4, 3, 0, 1, 2, 8},
                                              {1, 3, 5, 2, 1, 18},
                                              {6, 2, 6, 3, 2, 14},
                                              {7, 9, 0, 5, 4, 43},
                                              {5, 7, 8, 4, 0, 35} };

    gaussJordan(matrix, n);

    std::cout << "Solution:" << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << "x" << i + 1 << " = " << matrix[i][n] << std::endl;
    }

    return 0;
}
