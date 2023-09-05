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

    template<class T>
    void createNewArray(T **array, int size) {
        *array = new T[size];
        for (int i = 0; i < size; i++) {
            (*array)[i] = 0;
        }
    }

    template<class T>
    void showArray(T *arr, int size) {
        if (size == 0) return;
        std::cout << "[";
        for (int i = 0; i < size; i++) {
            if (i != size - 1) {
                std::cout << arr[i] << ", ";
            } else std::cout << arr[i] << "]" << std::endl;
        }
    }

    void help();
    int input(Matrix &matrix);
    void getCounts(int &cnt, int minCorner, int maxCorner);
    void showMatrix(Matrix matrix);
    double *individualTask(Matrix *matrix);
    void showAnswer(double *ans, int n);
    void deleteMatrix(Matrix &matrix);
}

