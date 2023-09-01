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
            delete matrix.lines[i].array;
        }
        delete matrix.lines;
    }

    int input(Matrix &matrix) {
        std::cout << "Input lines >>> ";
        getNum(matrix.n);
        matrix.lines = new Line[matrix.n];
        for (int i = 0; i < matrix.n; i++) {
            std::cout << "Input columns for line number " << i << " >>> ";
            getNum(matrix.lines[i].m);
            matrix.lines[i].array = new double[matrix.lines[i].m];
            for (int j = 0; j < matrix.lines[i].m; j++) {
                std::cout << "Input matrix[" << i << "][" << j << "]";
                getNum(matrix.lines[i].array[j]);
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
            len = min(matrix->lines[(i - 1) % matrix->n].m, matrix->lines[i % matrix->n].m);
            for (int j = 0; j < len; j++) {
                if (matrix->lines[(i - 1) % matrix->n].array[j] < matrix->lines[i % matrix->n].array[j]) {
                    sum += matrix->lines[i % matrix->n].array[j];
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
            for (int j = 0; j < matrix.lines[i].m; j++) {
                if (j != matrix.lines[i].m - 1) std::cout << matrix.lines[i].array[j] << ", ";
                else std::cout << matrix.lines[i].array[j];
            }
            std::cout << "]\n";
        }
    }
}

