// ============================================================
// 矩阵对战游戏
// 双方各 10 个棋子，每个棋子是一个 4x4 矩阵。
// 棋子相遇时比较行列式大小，也可以使用矩阵技能改变棋子。
//
// 编译：g++ version2.2.cpp -o 矩阵对战.exe -std=c++11 -mwindows
// 运行：rules.txt 需与程序位于同一目录
// ============================================================

#include <windows.h>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <limits>
#include <algorithm>
using namespace std;

/* ---------------- 常量 ---------------- */
const int BOARD_SIZE = 5;        // 棋盘 5x5
const int CELL_SIZE = 50;        // 每格边长
const int BOARD_X = 50;          // 棋盘左上角 x 坐标
const int BOARD_Y = 60;          // 棋盘左上角 y 坐标
const int MATRIX_SIZE = 4;       // 棋子矩阵阶数
const int MAX_DIM = 20;          // 矩阵数组最大维度
const int PIECE_COUNT = 20;      // 棋子总数（双方各 10）
const int PLAYER1_LAST_ID = 10;  // 编号 1~10 属于玩家 1
const int BUTTON_COUNT = 11;     // 按钮个数

/* ---------------- 矩阵类 ---------------- */
class Matrix {
private:
    int n;  // 矩阵阶数

public:
    double a[MAX_DIM][MAX_DIM];        // 当前矩阵
    double ta[MAX_DIM][MAX_DIM];       // 运算副本
    double duijiao[MAX_DIM][MAX_DIM];  // 对角化结果
    double ni[MAX_DIM][MAX_DIM];       // 逆矩阵结果

    // 构造：默认 4 阶，随机初始化
    Matrix(int nn = MATRIX_SIZE) {
        n = nn;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = (double)rand() / RAND_MAX * 10;
                ta[i][j] = a[i][j];
            }
        }
    }

    // 把 a 复制到 ta，供各运算使用
    void fuzhi() {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ta[i][j] = a[i][j];
            }
        }
    }

    // 高斯消元，化为上三角矩阵，结果存入 duijiao
    void duijiaohua() {
        fuzhi();
        for (int j = 1; j <= n; j++) {
            int k = 0;
            // 在第 j 列中从第 j 行往下找第一个非零元
            for (int i = j; i <= n; i++) {
                if (ta[i][j] != 0.0) {
                    k = i;
                    break;
                }
            }
            if (k == 0) continue;  // 该列下方全为 0，跳过
            // 把主元所在行交换到第 j 行
            for (int i = 1; i <= n; i++) {
                swap(ta[j][i], ta[k][i]);
            }
            // 用第 j 行消去下方各行
            for (int i = j + 1; i <= n; i++) {
                if (ta[i][j] != 0) {
                    for (int l = 1; l <= n; l++) {
                        ta[i][l] = ta[i][l] + (-1.0 * ta[i][j] / ta[j][j]) * ta[j][l];
                    }
                    ta[i][j] = 0;
                }
            }
        }
        // 将结果复制到 duijiao
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                duijiao[i][j] = ta[i][j];
            }
        }
    }

    // 对角化，并把结果写回 a（技能：对角化）
    void fuzhiduijiao() {
        duijiaohua();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = duijiao[i][j];
            }
        }
    }

    // 求逆，并把结果写回 a（技能：求逆）
    void fuzhini() {
        qiuni();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = ni[i][j];
            }
        }
    }

    // 转置（技能：转置）
    void zhuanzhi() {
        fuzhi();
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = ta[j][i];
            }
        }
    }

    // 行列式（上三角对角线元素之积）
    double hanglieshi() {
        duijiaohua();
        double tot = 1.0;
        for (int i = 1; i <= n; i++) {
            tot *= duijiao[i][i];
        }
        return tot;
    }

    // 秩
    int zhi() {
        duijiaohua();
        int rank = 0;
        for (int i = 1; i <= n; i++) {
            if (duijiao[i][i] != 0.0) {
                rank++;
            } else {
                break;
            }
        }
        return rank;
    }

    // 求逆（初等行变换法），结果存入 ni
    void qiuni() {
        if (zhi() != n) {
            cout << "矩阵不可逆" << endl;
            return;
        }
        fuzhi();
        // 初始化单位矩阵
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ni[i][j] = (i == j) ? 1.0 : 0.0;
            }
        }
        // 前向消元：左侧化为上三角
        for (int j = 1; j <= n; j++) {
            int k = 0;
            for (int i = j; i <= n; i++) {
                if (ta[i][j] != 0.0) {
                    k = i;
                    break;
                }
            }
            if (k == 0) continue;
            for (int i = 1; i <= n; i++) {
                swap(ta[j][i], ta[k][i]);
                swap(ni[j][i], ni[k][i]);
            }
            for (int i = j + 1; i <= n; i++) {
                if (ta[i][j] != 0) {
                    for (int l = 1; l <= n; l++) {
                        ni[i][l] = ni[i][l] + (-1.0 * ta[i][j] / ta[j][j]) * ni[j][l];
                        ta[i][l] = ta[i][l] + (-1.0 * ta[i][j] / ta[j][j]) * ta[j][l];
                    }
                    ta[i][j] = 0;
                }
            }
        }
        // 反向消元：左侧化为对角阵
        for (int j = n; j >= 1; j--) {
            int k = 0;
            for (int i = n; i >= j; i--) {
                if (ta[i][j] != 0.0) {
                    k = i;
                    break;
                }
            }
            if (k == 0) continue;
            for (int i = 1; i <= n; i++) {
                swap(ta[j][i], ta[k][i]);
                swap(ni[j][i], ni[k][i]);
            }
            for (int i = j - 1; i >= 1; i--) {
                if (ta[i][j] != 0) {
                    for (int l = j - 1; l >= 1; l--) {
                        if (ta[j][l] != 0) {
                            ni[i][l] = ni[i][l] + (-1.0 * ta[i][j] / ta[j][j]) * ni[j][l];
                            ta[i][l] = ta[i][l] + (-1.0 * ta[i][j] / ta[j][j]) * ta[j][l];
                        }
                    }
                    ta[i][j] = 0;
                }
            }
        }
        // 每一行除以对角元素，得到逆矩阵
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ni[i][j] /= ta[i][i];
            }
            ta[i][i] = 1;
        }
    }

    // 矩阵加法
    Matrix operator+(const Matrix &other) const {
        Matrix result(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                result.a[i][j] = a[i][j] + other.a[i][j];
            }
        }
        return result;
    }

    // 矩阵减法
    Matrix operator-(const Matrix &other) const {
        Matrix result(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                result.a[i][j] = a[i][j] - other.a[i][j];
            }
        }
        return result;
    }

    // 矩阵乘法
    Matrix operator*(const Matrix &other) const {
        Matrix result(n);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                result.a[i][j] = 0;
                for (int k = 1; k <= n; k++) {
                    result.a[i][j] += a[i][k] * other.a[k][j];
                }
            }
        }
        return result;
    }

    // 输入重载：读取 n 阶矩阵，非法输入时提示并重读
    friend istream &operator>>(istream &is, Matrix &m) {
        for (int i = 1; i <= m.n; i++) {
            for (int j = 1; j <= m.n; j++) {
                while (!(is >> m.a[i][j])) {
                    is.clear();
                    is.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "输入无效，请再输入一个有效数字: ";
                }
            }
        }
        return is;
    }

    // 输出重载
    friend ostream &operator<<(ostream &os, const Matrix &m) {
        for (int i = 1; i <= m.n; i++) {
            for (int j = 1; j <= m.n; j++) {
                os << m.a[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
};

/* ---------------- 游戏状态 ---------------- */
enum GameState {
    SELECTING,    // 选择棋子
    MOVING,       // 移动棋子
    USING_SKILL,  // 使用技能
    GAME_OVER     // 游戏结束
};

int amap[BOARD_SIZE + 1][BOARD_SIZE + 1];  // 棋盘，-1 表示空格
int currentPlayer = 1;                     // 当前玩家（1 或 2）
bool jineng[6][3] = {false};               // jineng[技能][玩家]：技能是否可用
Matrix ee(MATRIX_SIZE);                    // 单位矩阵 E
Matrix qizi[PIECE_COUNT + 1];              // 棋子矩阵，下标即棋子编号
GameState gameState = SELECTING;
int selectedRow = -1, selectedCol = -1;    // 当前选中的格子
bool hasOperated = false;                  // 本回合是否已操作

HINSTANCE g_hInstance = NULL;              // 当前程序实例句柄

/* ---------------- 按钮 ---------------- */
class Button {
public:
    int x, y, width, height;
    const char *text;
    bool clicked;
};

Button buttons[BUTTON_COUNT];

// 创建全部按钮
void createButtons() {
    // 功能按钮
    buttons[0] = {50, 300, 100, 30, "查看信息", false};
    buttons[1] = {160, 300, 100, 30, "使用技能", false};
    buttons[2] = {270, 300, 100, 30, "移动棋子", false};
    buttons[3] = {380, 300, 100, 30, "结束回合", false};

    // 技能按钮
    buttons[4] = {50, 340, 100, 30, "加E", false};
    buttons[5] = {160, 340, 100, 30, "求逆", false};
    buttons[6] = {270, 340, 100, 30, "转置", false};
    buttons[7] = {380, 340, 100, 30, "对角化", false};
    buttons[8] = {490, 340, 100, 30, "减E", false};

    // 其他按钮
    buttons[9] = {600, 300, 100, 30, "结束游戏", false};
    buttons[10] = {710, 300, 100, 30, "查看规则", false};
}

/* ---------------- 游戏逻辑 ---------------- */
// 结束当前回合：切换玩家、清空选择、重置操作标记
void endTurn() {
    currentPlayer = 3 - currentPlayer;
    gameState = SELECTING;
    selectedRow = -1;
    selectedCol = -1;
    hasOperated = false;
}

// 判断棋子是否属于当前玩家
bool isCurrentPlayerPiece(int pieceId) {
    if (currentPlayer == 1) {
        return pieceId >= 1 && pieceId <= PLAYER1_LAST_ID;
    }
    return pieceId > PLAYER1_LAST_ID && pieceId <= PIECE_COUNT;
}

// 统计棋盘上双方剩余的棋子数
void countPieces(int &player1Count, int &player2Count) {
    player1Count = 0;
    player2Count = 0;
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            if (amap[i][j] >= 1 && amap[i][j] <= PLAYER1_LAST_ID) {
                player1Count++;
            } else if (amap[i][j] > PLAYER1_LAST_ID && amap[i][j] <= PIECE_COUNT) {
                player2Count++;
            }
        }
    }
}

// 初始化游戏
void initGame() {
    // 初始化技能：双方都可使用 1~5 号技能
    for (int i = 1; i <= 5; i++) {
        jineng[i][1] = 1;
        jineng[i][2] = 1;
    }

    // 初始化棋盘为空
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            amap[i][j] = -1;
        }
    }

    // 玩家 1 的棋子：1~10，初始位于上方两行
    for (int i = 1; i <= 2; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            amap[i][j] = (i - 1) * BOARD_SIZE + j;
        }
    }

    // 玩家 2 的棋子：11~20，初始位于下方两行
    for (int i = 4; i <= 5; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            amap[i][j] = (i - 3) * BOARD_SIZE + j + 5;
        }
    }

    // 初始化单位矩阵 E
    for (int i = 1; i <= MATRIX_SIZE; i++) {
        for (int j = 1; j <= MATRIX_SIZE; j++) {
            ee.a[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // 以当前系统时间为随机数种子，保证每局矩阵不同
    srand((unsigned)time(NULL));
    for (int i = 1; i <= PIECE_COUNT; i++) {
        qizi[i] = Matrix(MATRIX_SIZE);
    }

    gameState = SELECTING;
    currentPlayer = 1;
    selectedRow = -1;
    selectedCol = -1;
    hasOperated = false;
}

/* ---------------- 绘图 ---------------- */
// 绘制按钮（GDI）
void drawButtons(HDC hdc) {
    for (int i = 0; i < BUTTON_COUNT; i++) {
        Button &btn = buttons[i];
        // 技能按钮只在“使用技能”状态下显示
        if (i >= 4 && i <= 8 && gameState != USING_SKILL) continue;

        // 按钮底色：按下为深色，未按下为浅色
        HBRUSH brush = CreateSolidBrush(btn.clicked ? RGB(150, 150, 255) : RGB(200, 200, 255));
        RECT rect;
        rect.left = btn.x;
        rect.top = btn.y;
        rect.right = btn.x + btn.width;
        rect.bottom = btn.y + btn.height;
        FillRect(hdc, &rect, brush);
        DeleteObject(brush);

        // 按钮边框
        HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, pen);
        Rectangle(hdc, btn.x, btn.y, btn.x + btn.width, btn.y + btn.height);
        SelectObject(hdc, oldPen);
        DeleteObject(pen);

        // 按钮文字
        SetBkMode(hdc, TRANSPARENT);
        TextOut(hdc, btn.x + 10, btn.y + 8, btn.text, strlen(btn.text));
    }
}

// 绘制整个游戏界面
void drawGame(HDC hdc) {
    // 背景
    HBRUSH bgBrush = CreateSolidBrush(RGB(240, 240, 240));
    RECT bgRect = {0, 0, 1200, 1200};
    FillRect(hdc, &bgRect, bgBrush);
    DeleteObject(bgBrush);

    SetBkMode(hdc, TRANSPARENT);

    // 标题
    HFONT titleFont = CreateFont(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                 DEFAULT_PITCH | FF_DONTCARE, "Arial");
    HFONT oldFont = (HFONT)SelectObject(hdc, titleFont);
    TextOut(hdc, 200, 10, "矩阵对战游戏", strlen("矩阵对战游戏"));
    SelectObject(hdc, oldFont);
    DeleteObject(titleFont);

    // 当前玩家
    char playerInfo[50];
    sprintf(playerInfo, "当前玩家: %s", currentPlayer == 1 ? "玩家1" : "玩家2");
    TextOut(hdc, 20, 10, playerInfo, strlen(playerInfo));

    // 游戏状态
    const char *stateText = "";
    switch (gameState) {
    case SELECTING:   stateText = "状态: 选择棋子"; break;
    case MOVING:      stateText = "状态: 移动棋子"; break;
    case USING_SKILL: stateText = "状态: 使用技能"; break;
    case GAME_OVER:   stateText = "状态: 游戏结束"; break;
    }
    TextOut(hdc, 20, 40, stateText, strlen(stateText));

    // 棋盘
    for (int i = 1; i <= BOARD_SIZE; i++) {
        for (int j = 1; j <= BOARD_SIZE; j++) {
            int x = (j - 1) * CELL_SIZE + BOARD_X;
            int y = (i - 1) * CELL_SIZE + BOARD_Y;

            // 格子底色
            HBRUSH brush;
            if (selectedRow == i && selectedCol == j) {
                brush = CreateSolidBrush(RGB(0, 255, 150));  // 选中格子为绿色
            } else if ((i + j) % 2 == 0) {
                brush = CreateSolidBrush(RGB(220, 220, 220));
            } else {
                brush = CreateSolidBrush(RGB(180, 180, 180));
            }
            RECT rect;
            rect.left = x;
            rect.top = y;
            rect.right = x + CELL_SIZE;
            rect.bottom = y + CELL_SIZE;
            FillRect(hdc, &rect, brush);
            DeleteObject(brush);

            // 格子边框
            HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, pen);
            Rectangle(hdc, x, y, x + CELL_SIZE, y + CELL_SIZE);
            SelectObject(hdc, oldPen);
            DeleteObject(pen);

            // 棋子编号
            if (amap[i][j] != -1) {
                char buffer[10];
                sprintf(buffer, "%d", amap[i][j]);
                TextOut(hdc, x + CELL_SIZE / 2 - 5, y + CELL_SIZE / 2 - 8, buffer, strlen(buffer));
            }
        }
    }

    drawButtons(hdc);

    // 选中棋子的信息
    if (selectedRow != -1 && selectedCol != -1 && amap[selectedRow][selectedCol] != -1) {
        int id = amap[selectedRow][selectedCol];
        char info[100];
        sprintf(info, "选中棋子: %d", id);
        TextOut(hdc, 350, 60, info, strlen(info));
        sprintf(info, "行列式: %.2f", qizi[id].hanglieshi());
        TextOut(hdc, 350, 80, info, strlen(info));
        sprintf(info, "秩: %d", qizi[id].zhi());
        TextOut(hdc, 350, 100, info, strlen(info));
    }
}

/* ---------------- 交互逻辑 ---------------- */
// 弹出选中棋子的矩阵信息
void showMatrixInfo(HWND hwnd, int row, int col) {
    if (row == -1 || col == -1 || amap[row][col] == -1) return;

    int pieceId = amap[row][col];
    Matrix &matrix = qizi[pieceId];
    char title[50];
    sprintf(title, "棋子 %d 的矩阵信息", pieceId);

    char info[1000] = "";
    char buffer[200];
    strcat(info, "矩阵:\n");
    for (int i = 1; i <= MATRIX_SIZE; i++) {
        for (int j = 1; j <= MATRIX_SIZE; j++) {
            sprintf(buffer, "%8.2f", matrix.a[i][j]);
            strcat(info, buffer);
        }
        strcat(info, "\n");
    }
    sprintf(buffer, "\n行列式: %.2f\n", matrix.hanglieshi());
    strcat(info, buffer);
    sprintf(buffer, "秩: %d\n", matrix.zhi());
    strcat(info, buffer);

    MessageBox(hwnd, info, title, MB_OK);
}

// 移动棋子
void movePiece(int fromRow, int fromCol, int toRow, int toCol, HWND hwnd) {
    if (fromRow == -1 || fromCol == -1 || amap[fromRow][fromCol] == -1) return;

    if (hasOperated) {
        MessageBox(hwnd, "该回合已进行操作，无法再次移动", "提示", MB_OK | MB_ICONINFORMATION);
        return;
    }

    int pieceId = amap[fromRow][fromCol];

    // 3 号和 18 号棋子不能移动
    if (pieceId == 3 || pieceId == 18) {
        MessageBox(hwnd, "不能移动棋子 3 和 18!", "提示", MB_OK | MB_ICONINFORMATION);
        gameState = SELECTING;
        return;
    }

    // 只能移动自己的棋子
    if (!isCurrentPlayerPiece(pieceId)) {
        MessageBox(hwnd, "只能移动自己的棋子!", "提示", MB_OK | MB_ICONINFORMATION);
        gameState = SELECTING;
        return;
    }

    // 只能直线移动
    if ((fromRow != toRow && fromCol != toCol) || (fromRow == toRow && fromCol == toCol)) {
        MessageBox(hwnd, "只能垂直或水平移动棋子!", "提示", MB_OK | MB_ICONINFORMATION);
        gameState = SELECTING;
        return;
    }

    if (amap[toRow][toCol] != -1) {
        int targetId = amap[toRow][toCol];
        if (isCurrentPlayerPiece(targetId)) {
            // 同玩家棋子合并（矩阵相加）
            qizi[targetId] = qizi[targetId] + qizi[pieceId];
            amap[fromRow][fromCol] = -1;
            MessageBox(hwnd, "棋子合并成功!", "提示", MB_OK | MB_ICONINFORMATION);
        } else {
            // 不同玩家棋子对战，比较行列式绝对值
            double attackerDet = qizi[pieceId].hanglieshi();
            double defenderDet = qizi[targetId].hanglieshi();
            if (fabs(attackerDet) > fabs(defenderDet)) {
                amap[toRow][toCol] = pieceId;
                amap[fromRow][fromCol] = -1;
                MessageBox(hwnd, "攻击成功，对方棋子被移除!", "提示", MB_OK | MB_ICONINFORMATION);
            } else if (fabs(attackerDet) < fabs(defenderDet)) {
                amap[fromRow][fromCol] = -1;
                MessageBox(hwnd, "攻击失败，自己的棋子被移除!", "提示", MB_OK | MB_ICONINFORMATION);
            } else {
                amap[fromRow][fromCol] = -1;
                amap[toRow][toCol] = -1;
                MessageBox(hwnd, "双方平局，两枚棋子都被移除!", "提示", MB_OK | MB_ICONINFORMATION);
            }
        }
    } else {
        // 目标格子为空，直接移动
        amap[toRow][toCol] = pieceId;
        amap[fromRow][fromCol] = -1;
    }

    // 被动结束判定：任意一方棋子数少于 3 时，比较 3 号和 18 号的行列式
    int player1Count = 0, player2Count = 0;
    countPieces(player1Count, player2Count);
    if (player1Count < 3 || player2Count < 3) {
        double det3 = qizi[3].hanglieshi();
        double det18 = qizi[18].hanglieshi();
        if (det3 > det18) {
            MessageBox(hwnd, "玩家 1 获胜（棋子 3 的行列式大于棋子 18）", "游戏结束", MB_OK | MB_ICONINFORMATION);
        } else if (det3 < det18) {
            MessageBox(hwnd, "玩家 2 获胜（棋子 18 的行列式大于棋子 3）", "游戏结束", MB_OK | MB_ICONINFORMATION);
        } else {
            MessageBox(hwnd, "平局（棋子 3 与棋子 18 的行列式相等）", "游戏结束", MB_OK | MB_ICONINFORMATION);
        }
        gameState = GAME_OVER;
    }

    hasOperated = true;  // 本回合已操作
    endTurn();           // 结束回合（新回合会重置操作标记）
}

// 使用技能
void useSkill(int skill, int row, int col, HWND hwnd) {
    if (row == -1 || col == -1 || amap[row][col] == -1) return;

    if (hasOperated) {
        MessageBox(hwnd, "该回合已进行操作，无法再次移动", "提示", MB_OK | MB_ICONINFORMATION);
        return;
    }

    int pieceId = amap[row][col];

    // 检查技能是否可用
    if (!jineng[skill][currentPlayer]) {
        MessageBox(hwnd, "该技能不可使用!", "提示", MB_OK | MB_ICONINFORMATION);
        return;
    }

    // 只能对自己的棋子使用技能
    if (!isCurrentPlayerPiece(pieceId)) {
        MessageBox(hwnd, "只能对自己的棋子使用技能!", "提示", MB_OK | MB_ICONINFORMATION);
        return;
    }

    switch (skill) {
    case 1:
        qizi[pieceId] = qizi[pieceId] + ee;
        MessageBox(hwnd, "加E技能使用成功!", "提示", MB_OK | MB_ICONINFORMATION);
        break;
    case 2:
        qizi[pieceId].fuzhini();
        MessageBox(hwnd, "求逆技能使用成功!", "提示", MB_OK | MB_ICONINFORMATION);
        break;
    case 3:
        qizi[pieceId].zhuanzhi();
        MessageBox(hwnd, "转置技能使用成功!", "提示", MB_OK | MB_ICONINFORMATION);
        break;
    case 4:
        qizi[pieceId].fuzhiduijiao();
        MessageBox(hwnd, "对角化技能使用成功!", "提示", MB_OK | MB_ICONINFORMATION);
        break;
    case 5:
        qizi[pieceId] = qizi[pieceId] - ee;
        MessageBox(hwnd, "减E技能使用成功!", "提示", MB_OK | MB_ICONINFORMATION);
        break;
    }

    // 标记技能已使用
    jineng[skill][currentPlayer] = 0;
    hasOperated = true;  // 本回合已操作

    endTurn();  // 结束回合
    InvalidateRect(hwnd, NULL, TRUE);
}

/* ---------------- 窗口过程 ---------------- */
// 规则窗口：显示 rules.txt 的内容
LRESULT CALLBACK RulesWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        // 从 rules.txt 读取规则文本
        char buffer[1024] = {};
        FILE *file = fopen("rules.txt", "r");
        if (file) {
            fread(buffer, sizeof(char), sizeof(buffer) - 1, file);
            fclose(file);
        } else {
            strcpy(buffer, "游戏规则文件未找到！");
        }

        RECT rect;
        GetClientRect(hwnd, &rect);
        DrawTextA(hdc, buffer, -1, &rect, DT_LEFT | DT_WORDBREAK);
        EndPaint(hwnd, &ps);
        break;
    }
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 打开规则窗口（窗口类只注册一次）
void openRulesWindow(HWND hwnd) {
    static bool registered = false;
    const char RULES_CLASS_NAME[] = "RulesWindowClass";

    if (!registered) {
        WNDCLASS rulesWC = {};
        rulesWC.lpfnWndProc = RulesWindowProc;
        rulesWC.hInstance = g_hInstance;
        rulesWC.lpszClassName = RULES_CLASS_NAME;
        rulesWC.hCursor = LoadCursor(NULL, IDC_ARROW);
        rulesWC.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

        if (!RegisterClass(&rulesWC)) {
            MessageBox(hwnd, "注册规则窗口类失败!", "错误", MB_OK | MB_ICONERROR);
            return;
        }
        registered = true;
    }

    HWND rulesHwnd = CreateWindowEx(0, RULES_CLASS_NAME, "游戏规则", WS_OVERLAPPEDWINDOW,
                                    CW_USEDEFAULT, CW_USEDEFAULT, 400, 300,
                                    NULL, NULL, g_hInstance, NULL);
    if (rulesHwnd) {
        ShowWindow(rulesHwnd, SW_SHOW);
        UpdateWindow(rulesHwnd);
    } else {
        MessageBox(hwnd, "创建规则窗口失败!", "错误", MB_OK | MB_ICONERROR);
    }
}

// 处理按钮点击，返回按钮编号对应的操作
void handleButtonClick(int index, HWND hwnd) {
    switch (index) {
    case 0:  // 查看信息
        showMatrixInfo(hwnd, selectedRow, selectedCol);
        break;

    case 1:  // 使用技能
        gameState = USING_SKILL;
        break;

    case 2:  // 移动棋子
        gameState = MOVING;
        break;

    case 3:  // 结束回合
        endTurn();
        break;

    case 4:  // 加E
    case 5:  // 求逆
    case 6:  // 转置
    case 7:  // 对角化
    case 8:  // 减E
        if (selectedRow != -1 && selectedCol != -1) {
            useSkill(index - 3, selectedRow, selectedCol, hwnd);
        } else {
            MessageBox(hwnd, "请先选择一个棋子!", "提示", MB_OK | MB_ICONINFORMATION);
        }
        break;

    case 9: {  // 结束游戏：按剩余棋子数判胜负
        gameState = GAME_OVER;
        int player1Count = 0, player2Count = 0;
        countPieces(player1Count, player2Count);

        char result[100];
        if (player1Count > player2Count) {
            sprintf(result, "游戏结束，玩家1获胜\n玩家1剩余棋子: %d\n玩家2剩余棋子: %d", player1Count, player2Count);
        } else if (player1Count < player2Count) {
            sprintf(result, "游戏结束，玩家2获胜\n玩家1剩余棋子: %d\n玩家2剩余棋子: %d", player1Count, player2Count);
        } else {
            sprintf(result, "游戏结束，平局\n玩家1剩余棋子: %d\n玩家2剩余棋子: %d", player1Count, player2Count);
        }
        MessageBox(hwnd, result, "游戏结束", MB_OK | MB_ICONINFORMATION);
        PostQuitMessage(0);
        break;
    }

    case 10:  // 查看规则
        openRulesWindow(hwnd);
        break;
    }
}

// 处理棋盘点击
void handleBoardClick(int row, int col, HWND hwnd) {
    if (gameState == SELECTING) {
        selectedRow = row;
        selectedCol = col;
    } else if (gameState == MOVING) {
        if (selectedRow != -1 && selectedCol != -1) {
            movePiece(selectedRow, selectedCol, row, col, hwnd);
            selectedRow = -1;
            selectedCol = -1;
        }
    }
    InvalidateRect(hwnd, NULL, TRUE);
}

// 主窗口过程
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        g_hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
        initGame();
        createButtons();
        break;

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        drawGame(hdc);
        EndPaint(hwnd, &ps);
        break;
    }

    case WM_LBUTTONDOWN: {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        // 按钮点击
        for (int i = 0; i < BUTTON_COUNT; i++) {
            Button &btn = buttons[i];
            if (x >= btn.x && x <= btn.x + btn.width &&
                y >= btn.y && y <= btn.y + btn.height) {
                btn.clicked = true;
                handleButtonClick(i, hwnd);
                break;
            }
        }

        // 棋盘点击
        int boardRight = BOARD_X + BOARD_SIZE * CELL_SIZE;
        int boardBottom = BOARD_Y + BOARD_SIZE * CELL_SIZE;
        if (x >= BOARD_X && x < boardRight && y >= BOARD_Y && y < boardBottom) {
            int col = (x - BOARD_X) / CELL_SIZE + 1;
            int row = (y - BOARD_Y) / CELL_SIZE + 1;
            handleBoardClick(row, col, hwnd);
        }
        break;
    }

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    default:
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

/* ---------------- 入口 ---------------- */
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {
    const char CLASS_NAME[] = "MatrixGameClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    RegisterClass(&wc);

    // 窗口宽度需容纳全部按钮（最右侧按钮到 x = 810）
    HWND hwnd = CreateWindowEx(0, CLASS_NAME, "矩阵对战游戏", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, 900, 460,
                               NULL, NULL, hInstance, NULL);
    if (hwnd == NULL) {
        return 0;
    }

    ShowWindow(hwnd, iCmdShow);
    UpdateWindow(hwnd);

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}
