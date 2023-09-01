#include <iostream>
#include "matrix.h"

namespace Input {
    int getNum(int &a) {
        std::cin >> a;
        if (!std::cin.good()) return -1;
        return 1;
    }

    void deleteMatrix(Matrix &matrix) {
        for (int i = 0; i < matrix.n; i++) {
            delete matrix.array[i];
        }
        delete matrix.array;
    }

    int input(Matrix &matrix) {
        std::cout << "Input lines >>> ";
        getNum(matrix.n);
        matrix.array = new double*[matrix.n];
        std::cout << "Input columns >>> ";
        getNum(matrix.m);
        for (int i = 0; i < matrix.n; i++) {
            matrix.array[i] = new double[matrix.m];
            for (int j = 0; j < matrix.m; j++) {
                std::cout << "Input matrix[" << i << "][" << j << "]";
                getNum(matrix.array[i][j]);
            }
        }
        return 0;
    }

    void help() {
        std::cout << "COMMANDS:" << std::endl << "0 - Exit programm;" << std::endl << "1 - Initial matrix;" <<  std::endl << "2 - Get answer;" << std::endl << "3 - Show matrix;" << std::endl << "9 - Instruction;" << std::endl;
    }

    double* individualTask(Matrix *matrix) {
        if (matrix->n == 0) {
            std::cout << "Matrix is free. Try to initial matrix and repeat this action." << std::endl;
            return nullptr;
        }
        double *answer = new double[matrix->n];
        double sum;
        int len;
        for (int i = 0; i < matrix->n; i++) {
            answer[i] = 0;
        }
        for (int i = 1; i < matrix->n + 1; i++) {
            sum = 0;
            for (int j = 0; j < matrix->m; j++) {
                if (matrix->array[(i - 1) % matrix->n][j] < matrix->array[i % matrix->n][j]) {
                    sum += matrix->array[i % matrix->n][j];
                }
            }
            answer[i % matrix->n] = sum;
        }
        return answer;
    }

    void showAnswer(double *ans, int n) {
        std::cout << "ANSWER:" << std::endl;
        std::cout << "[";
        for (int i = 0; i < n; i++) {
            if (i != n - 1) std::cout << ans[i] << ", ";
            else std::cout << ans[i];
        }
        std::cout << "]\n";
    }

    void showMatrix(Matrix matrix) {
        if (matrix.n == 0) {
            std::cout << "Matrix is free. Try to initial matrix and repeat this action." << std::endl;
            return;
        }
        std::cout << "MATRIX: " << std::endl;
        for (int i = 0; i < matrix.n; i++) {
            std::cout << "[";
            for (int j = 0; j < matrix.m; j++) {
                if (j != matrix.m - 1) std::cout << matrix.array[i][j] << ", ";
                else std::cout << matrix.array[i][j];
            }
            std::cout << "]\n";
        }
    }
}

