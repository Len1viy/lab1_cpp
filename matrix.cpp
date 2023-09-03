#include <iostream>
#include "matrix.h"

namespace Input {
    int getNum(int &a) {
        std::cin >> a;
        if (!std::cin.good()) return -1;
        return 1;
    }

    void deleteMatrix(Matrix &matrix) {
        delete matrix.columnIndexes;
        delete matrix.rowIndexes;
        delete matrix.values;
        matrix.n = 0;
        matrix.m = 0;
        matrix.countOfValues = 0;
    }

    void createNewArray(int **array, int size) {
        *array = new int[size];
        for (int i = 0; i < size; i++) {
            (*array)[i] = 0;
        }
    }

    void getCounts(int &cnt, int minCorner, int maxCorner) {
        getNum(cnt);
        while (cnt > maxCorner || cnt < minCorner) {
            std::cout << "Try again >>>";
            getNum(cnt);
        }
    }

    int input(Matrix &matrix) {
        int count = 0;
        int currentCount = 0;
        std::cout << "Input lines >>> ";
        getNum(matrix.n);
        matrix.rowIndexes = new int[matrix.n + 1];
        matrix.rowIndexes[0] = 0;
        std::cout << "Input columns >>> ";
        getNum(matrix.m);
        std::cout << "Input count of not null elements in matrix >>> ";
        getCounts(matrix.countOfValues, 0, matrix.m * matrix.n);
        matrix.columnIndexes = new int[count];
        matrix.values = new double[count];
        for (int i = 0; i < matrix.n; i++) {
            std::cout << matrix.countOfValues - currentCount << " items left" << std::endl;
            std::cout << "Input count of not null elements in line " << i << " >>> ";
            getCounts(count, 0, matrix.countOfValues - currentCount);
            currentCount += count;
            matrix.rowIndexes[i + 1] = currentCount;
            for (int j = 0; j < count; j++) {
                std::cout << "Input index of value number " << i << " in line " << i << " >>> ";
                getCounts(matrix.columnIndexes[currentCount - count + j], 0, matrix.m - 1);
                std::cout << "Input element of [" << i << "]" << "[" << matrix.columnIndexes[currentCount - count + j] << "]";
                getNum(matrix.values[currentCount - count + j]);
            }
        }
        for (int i = 0; i < matrix.n + 1; i++) {
            std::cout << matrix.rowIndexes[i] << " ";
        }
        std::cout << "\n";

        for (int i = 0; i < matrix.countOfValues; i++) {
            std::cout << matrix.columnIndexes[i] << " ";
        }
        std::cout << "\n";
        for (int i = 0; i < matrix.countOfValues; i++) {
            std::cout << matrix.values[i] << " ";
        }
        std::cout << "\n";
        return 0;
    }

    void help() {
        std::cout << "COMMANDS:" << std::endl << "0 - Exit programm;" << std::endl << "1 - Initial matrix;" <<  std::endl << "2 - Get answer;" << std::endl << "3 - Show matrix;" << std::endl << "9 - Instruction;" << std::endl;
    }

    double* individualTask(Matrix *matrix) {
        return nullptr;
//        if (matrix->n == 0) {
//            std::cout << "Matrix is free. Try to initial matrix and repeat this action." << std::endl;
//            return nullptr;
//        }
//        double *answer = new double[matrix->n];
//        double sum;
//        int len;
//        for (int i = 0; i < matrix->n; i++) {
//            answer[i] = 0;
//        }
//        for (int i = 1; i < matrix->n + 1; i++) {
//            sum = 0;
//            for (int j = 0; j < matrix->m; j++) {
//                if (matrix->array[(i - 1) % matrix->n][j] < matrix->array[i % matrix->n][j]) {
//                    sum += matrix->array[i % matrix->n][j];
//                }
//            }
//            answer[i % matrix->n] = sum;
//        }
//        return answer;
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
        if (matrix.n == 0 || matrix.m == 0) {
            std::cout << "Matrix is free. Try to initial matrix and repeat this action." << std::endl;
            return;
        }
        std::cout << "MATRIX: " << std::endl;
        int *array;
        createNewArray(&array, matrix.m);
        for (int i = 0; i < matrix.n; i++) {
            int startIndex = matrix.rowIndexes[i];
            int endIndex = matrix.rowIndexes[i + 1];
            for (int j = startIndex; j < endIndex; j++) {
                array[matrix.columnIndexes[j]] = matrix.values[j];
            }
            std::cout << "[";
            for (int element = 0; element < matrix.m; element++) {
                if (element != matrix.m - 1) std::cout << array[element] << ", ";
                else std::cout << array[element] << "]\n";
                array[element] = 0;
            }
        }
    }
}

