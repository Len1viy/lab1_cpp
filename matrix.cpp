#include <iostream>
#include "matrix.h"

// Сделать проверку на ввод элемента в уже занятую ячейку

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
        std::cout << "Input columns >>> ";
        getNum(matrix.m);
        std::cout << "Input count of not null elements in matrix >>> ";
        getCounts(matrix.countOfValues, 0, matrix.m * matrix.n);
        createNewArray(&matrix.values, count);
        createNewArray(&matrix.columnIndexes, count);
        createNewArray(&matrix.rowIndexes, matrix.n+1);
        matrix.rowIndexes[0] = 0;
        for (int i = 0; i < matrix.n; i++) {
            if (matrix.countOfValues == currentCount) {
                matrix.rowIndexes[i + 1] = currentCount;
                continue;
            }
            std::cout << matrix.countOfValues - currentCount << " items left" << std::endl;
            std::cout << "Input count of not null elements in line " << i << " >>> ";
            getCounts(count, 0, matrix.countOfValues - currentCount);
            currentCount += count;
            matrix.rowIndexes[i + 1] = currentCount;
            for (int j = 0; j < count; j++) {
                std::cout << "Input index of value number " << j << " in line " << i << " >>> ";
                getCounts(matrix.columnIndexes[currentCount - count + j], 0, matrix.m - 1);
                std::cout << "Input element of [" << i << "]" << "[" << matrix.columnIndexes[currentCount - count + j]
                          << "]";
                getNum(matrix.values[currentCount - count + j]);
            }
        }

        return 0;
    }

    void help() {
        std::cout << "COMMANDS:" << std::endl << "0 - Exit programm;" << std::endl << "1 - Initial matrix;" << std::endl
                  << "2 - Get answer;" << std::endl << "3 - Show matrix;" << std::endl << "9 - Instruction;"
                  << std::endl;
    }

    double *individualTask(Matrix *matrix) {
        if (matrix->n == 0) {
            std::cout << "Matrix is free. Try to initial matrix and repeat this action." << std::endl;
            return nullptr;
        }
        double *answer;
        createNewArray(&answer, matrix->n);
        double sum;
        int len, curCnt, prevCnt;
        double *curLine;
        createNewArray(&curLine, matrix->n);
        double *prevLine;
        createNewArray(&prevLine, matrix->n);
        for (int i = 1; i < matrix->n + 1; i++) {
            sum = 0;
            int startInd = matrix->rowIndexes[i - 1];
            int endInd = matrix->rowIndexes[i];
            if (i == 1) {
                prevCnt = endInd - startInd;
                for (int j = startInd; j < endInd; j++) {
                    prevLine[matrix->columnIndexes[j]] = matrix->values[j];
                }
            } else {
                curCnt = endInd - startInd;
                for (int j = startInd; j < endInd; j++) {
                    curLine[matrix->columnIndexes[j]] = matrix->values[j];
                }
                for (int j = 0; j < matrix->m; j++) {
                    if (curLine[j] > prevLine[j] && curLine[j] != 0) {
                        sum += curLine[j];
                    }
                    prevLine[j] = curLine[j];
                    curLine[j] = 0;
                }
                answer[i - 1] = sum;
            }
        }
        sum = 0;
        for (int j = 0; j < matrix->rowIndexes[1]; j++) {
            curLine[matrix->columnIndexes[j]] = matrix->values[j];
        }
        for (int j = 0; j < matrix->m; j++) {
            if (curLine[j] > prevLine[j] && curLine[j] != 0) {
                sum += curLine[j];
            }
        }
        answer[0] = sum;
        return answer;
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

