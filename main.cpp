#include <iostream>

struct Matrix {
    int array;
};


int Dialog() {
    int n;
    int m;
    std::cout << "����� �����c⢮ �⮫�殢 � �����: " << std::endl;
    std::cin >> n;
    std::cout << "����� �����c⢮ ��ப � �����: " << std::endl;
    std::cin >> m;
    std::cout << "n = " << n << "; m = " << m << std::endl;

    return 0;
}


int main() {
    Dialog();
    return 0;
}
