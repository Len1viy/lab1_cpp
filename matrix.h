namespace Input {
    struct Line {
        int m;
        double *array;
    };

    struct Matrix {
        int n;
        Line *lines;
    };


    template<class T>
    int getNum(T &a) {
        std::cin >> a;
        if (!std::cin.good()) return -1;
        return 1;
    }

    template<class T>
    T min(T a, T b) {
        if (a < b) return a;
        else return b;
    }

    void help();
    int input(Matrix &matrix);
    void showMatrix(Matrix matrix);
    double *individualTask(Matrix *matrix);
    void showAnswer(double *ans, int n);
    void deleteMatrix(Matrix &matrix);
}

