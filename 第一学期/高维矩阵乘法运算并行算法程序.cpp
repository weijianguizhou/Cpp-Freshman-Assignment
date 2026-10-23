#include <iostream>
#include <vector>
#include <omp.h>

using namespace std;

// 矩阵乘法函数
void tensorMultiplication(const vector<vector<vector<int> > >& A,
                          const vector<vector<vector<int> > >& B,
                          vector<vector<vector<int> > >& C) {
    int d1 = A.size();
    int d2 = A[0].size();
    int d3 = B[0][0].size();

    #pragma omp parallel for collapse(2) // 使用 OpenMP 并行化外层循环
    for (int i = 0; i < d1; ++i) {
        for (int j = 0; j < d2; ++j) {
            for (int k = 0; k < d3; ++k) {
                C[i][j][k] = 0; // 初始化结果矩阵 C
                for (int l = 0; l < A[0].size(); ++l) {
                    C[i][j][k] += A[i][j][l] * B[l][j][k];
                }
            }
        }
    }
}

int main() {
    // 定义矩阵的维度
    int d1 = 4, d2 = 4, d3 = 4;

    // 初始化三个三维矩阵
    vector<vector<vector<int> > > A(d1, vector<vector<int> >(d2, vector<int>(d2, 1))); // 示例矩阵 A
    vector<vector<vector<int> > > B(d2, vector<vector<int> >(d2, vector<int>(d3, 2))); // 示例矩阵 B
    vector<vector<vector<int> > > C(d1, vector<vector<int> >(d2, vector<int>(d3, 0))); // 结果矩阵 C

    // 执行矩阵乘法
    tensorMultiplication(A, B, C);

    // 输出结果矩阵
    for (int i = 0; i < d1; ++i) {
        for (int j = 0; j < d2; ++j) {
            for (int k = 0; k < d3; ++k) {
                cout << "C[" << i << "][" << j << "][" << k << "] = " << C[i][j][k] << endl;
            }
        }
    }

    return 0;
}
