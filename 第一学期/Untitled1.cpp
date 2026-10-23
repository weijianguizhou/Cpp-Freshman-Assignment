#include <iostream>
#include <vector>
#include <thread>

// 矩阵乘法函数
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    for (int i = 0; i < rowsA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            for (int k = 0; k < colsA; ++k) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    return result;
}

// 并行矩阵乘法函数
std::vector<std::vector<int>> parallelMatrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B, int numThreads) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    auto worker = [&](int startRow, int endRow) {
        for (int i = startRow; i < endRow; ++i) {
            for (int j = 0; j < colsB; ++j) {
                for (int k = 0; k < colsA; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    };

    int chunkSize = rowsA / numThreads;
    std::vector<std::thread> threads;
    for (int i = 0; i < numThreads; ++i) {
        int startRow = i * chunkSize;
        int endRow = (i == numThreads - 1)? rowsA : startRow + chunkSize;
        threads.push_back(std::thread(worker, startRow, endRow));
    }

    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    return result;
}

int main() {
    std::vector<std::vector<int>> A = { {1, 2}, {3, 4} };
    std::vector<std::vector<int>> B = { {5, 6}, {7, 8} };

    // 串行计算
    auto resultSerial = matrixMultiply(A, B);

    // 并行计算，使用 2 个线程
    auto resultParallel = parallelMatrixMultiply(A, B, 2);

    // 输出结果
    std::cout << "Serial Result:\n";
    for (const auto& row : resultSerial) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Parallel Result:\n";
    for (const auto& row : resultParallel) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
