#include <iostream>
#include "matrix.h"
using namespace Input;

int main() {
    Matrix matrix = Matrix();
    int command = -1;
    help();
    while (command != 0) {
        std::cout << "Your command >>> ";
        getNum(command);
        if (command == 1) {
            if (matrix.n != 0) deleteMatrix(matrix);
            input(matrix);
        }
        else if (command == 2) {
            showMatrix(matrix);
            double *answer = individualTask(&matrix);
            showAnswer(answer, matrix.n);
            delete answer;
        } else if (command == 3) {
            showMatrix(matrix);
        } else if (command == 9) {
            help();
        }
    }
    deleteMatrix(matrix);
    return 0;
}