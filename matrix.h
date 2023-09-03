namespace Input {
    struct Matrix {
        int n;
        int m;
        int countOfValues;
        int *rowIndexes;
        int *columnIndexes;
        double *values;
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
    void getCounts(int &cnt, int minCorner, int maxCorner);
    void showMatrix(Matrix matrix);
    double *individualTask(Matrix *matrix);
    void showAnswer(double *ans, int n);
    void deleteMatrix(Matrix &matrix);
    void createNewArray(int **array, int size);
}

