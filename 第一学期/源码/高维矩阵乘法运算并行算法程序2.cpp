#include <iostream>
#include <vector>
#include <thread>

// 矩阵乘法函数，用于串行计算
std::vector<std::vector<int>> matrixMultiply(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B) {
    int rowsA = A.size();
    int colsA = A[0].size();
    int colsB = B[0].size();

    // 创建用于存储结果的矩阵
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    // 三层循环进行矩阵乘法计算
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

    // 创建用于存储结果的矩阵
    std::vector<std::vector<int>> result(rowsA, std::vector<int>(colsB, 0));

    // 定义一个 lambda 函数作为线程的工作函数
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
        // 创建并启动一个线程，执行工作函数
        threads.push_back(std::thread(worker, startRow, endRow));
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        if (th.joinable()) {
            th.join();
        }
    }

    return result;
}

int main() {
    // 定义两个示例矩阵
    std::vector<std::vector<int>> A = { {1, 2}, {3, 4} };
    std::vector<std::vector<int>> B = { {5, 6}, {7, 8} };

    // 进行串行计算
    auto resultSerial = matrixMultiply(A, B);

    // 使用 2 个线程进行并行计算
    auto resultParallel = parallelMatrixMultiply(A, B, 2);

    // 输出串行计算结果
    std::cout << "Serial Result:\n";
    for (const auto& row : resultSerial) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    // 输出并行计算结果
    std::cout << "Parallel Result:\n";
    for (const auto& row : resultParallel) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }

    return 0;
}
