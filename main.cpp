#include <iostream>

struct Matrix {
    int array;
};


int Dialog() {
    int n;
    int m;
    std::cout << "Введи количеcтво столбцов в матрице: " << std::endl;
    std::cin >> n;
    std::cout << "Введи количеcтво строк в матрице: " << std::endl;
    std::cin >> m;
    std::cout << "n = " << n << "; m = " << m << std::endl;

    return 0;
}


int main() {
    Dialog();
    return 0;
}
