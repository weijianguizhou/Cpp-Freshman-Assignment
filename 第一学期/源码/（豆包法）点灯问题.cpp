#include <iostream>
#include <algorithm>

// 定义棋盘大小
const int BOARD_SIZE = 5;

// 切换指定格子及其上下左右相邻格子的灯的状态
void toggleLights(int matrix[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    int directions[5][2] = { {0, 0}, {0, 1}, {0, -1}, {1, 0}, {-1, 0} };

    for (int i = 0; i < 5; ++i) {
        int newRow = row + directions[i][0];
        int newCol = col + directions[i][1];

        if (newRow >= 0 && newRow < BOARD_SIZE && newCol >= 0 && newCol < BOARD_SIZE) {
            matrix[newRow][newCol] ^= 1;
        }
    }
}

// 检查矩阵中的所有灯是否都点亮
bool isAllLightsOn(int matrix[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; ++i) {
        for (int j = 0; j < BOARD_SIZE; ++j) {
            if (matrix[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

// 找到使所有灯都点亮的最少点击次数
std::pair<int, int[BOARD_SIZE * BOARD_SIZE]> findMinClicks(int initialMatrix[BOARD_SIZE][BOARD_SIZE]) {
    int minClicks = INT_MAX;
    int bestCombination[BOARD_SIZE * BOARD_SIZE];

    // 生成所有可能的点击组合
    int clickCombination[BOARD_SIZE * BOARD_SIZE];
    for (int i = 0; i < (1 << (BOARD_SIZE * BOARD_SIZE)); ++i) {
        int matrix[BOARD_SIZE][BOARD_SIZE];
        for (int m = 0; m < BOARD_SIZE; ++m) {
            for (int n = 0; n < BOARD_SIZE; ++n) {
                matrix[m][n] = initialMatrix[m][n];
            }
        }
        int clickCount = 0;

        // 根据当前组合设置点击情况并切换灯的状态
        for (int j = 0; j < BOARD_SIZE * BOARD_SIZE; ++j) {
            if (i & (1 << j)) {
                clickCombination[j] = 1;
                clickCount++;

                int row = j / BOARD_SIZE;
                int col = j % BOARD_SIZE;
                toggleLights(matrix, row, col);
            } else {
                clickCombination[j] = 0;
            }
        }

        // 如果所有灯都点亮且点击次数更少，更新最小点击次数和最佳组合
        if (isAllLightsOn(matrix) && clickCount < minClicks) {
            minClicks = clickCount;
            for (int k = 0; k < BOARD_SIZE * BOARD_SIZE; ++k) {
                bestCombination[k] = clickCombination[k];
            }
        }
    }

    return { minClicks, bestCombination };
}
int main() {
    // 示例初始灯状态矩阵，这里假设全部是熄灭状态（0），你可以根据实际情况修改
    int initialMatrix[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0}
    };

    auto result = findMinClicks(initialMatrix);
    std::cout << "最少点击次数: " << result.first << std::endl;

    std::cout << "最佳点击组合: ";
    for (int i = 0; i < BOARD_SIZE * BOARD_SIZE; ++i) {
        std::cout << result.second[i];
    }
    std::cout << std::endl;

    return 0;
}
