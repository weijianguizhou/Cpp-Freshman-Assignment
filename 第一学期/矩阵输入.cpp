#include <iostream>
using namespace std;

// 定义矩阵类，包含行数和列数
class Matrix {
private:
    int rows;
    int cols;
    int** data; // 二维动态数组

public:
    // 构造函数
    Matrix(int r, int c) : rows(r), cols(c) {
        data = new int*[rows];
        for (int i = 0; i < rows; ++i)
            data[i] = new int[cols];
    }

    // 输入矩阵元素
    void inputMatrix() {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                cout << "请输入第 " << (i+1) << "," << (j+1) << " 位置的值: ";
                cin >> data[i][j];
            }
        }
    }

    ~Matrix() { // 析构函数释放内存
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
    }
};

int main() {
    int rows, cols;
    cout << "请输入矩阵的行数和列数: ";
    cin >> rows >> cols;

    Matrix m(rows, cols);
    m.inputMatrix();

    // 显示输入的矩阵
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j)
            cout << m.data[i][j] << " ";
        cout << endl;
    }

    return 0;
}
