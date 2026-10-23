// ============================================================
// 矩阵对战游戏（完成版）
// 双方各 10 个棋子，每个棋子是一个 4x4 矩阵。
// 棋子相遇时比较行列式大小，也可以使用矩阵技能改变棋子。
//
// 构建：见 CMakeLists.txt（cmake -S . -B build && cmake --build build）
// 运行：rules.txt 需与程序位于同一目录（构建时会自动复制）
// ============================================================
#include <windows.h>

#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>

#include "Matrix.h"

using namespace std;

/* ---------------- 常量 ---------------- */
const int BOARD_SIZE = 5;        // 棋盘 5x5
const int CELL_SIZE = 50;        // 每格边长
const int BOARD_X = 50;          // 棋盘左上角 x 坐标
const int BOARD_Y = 60;          // 棋盘左上角 y 坐标
const int PIECE_COUNT = 20;      // 棋子总数（双方各 10）
const int PLAYER1_LAST_ID = 10;  // 编号 1~10 属于玩家 1
const int BUTTON_COUNT = 11;     // 按钮个数
const int WINDOW_WIDTH = 940;    // 窗口宽度（需容纳最右侧按钮）
const int WINDOW_HEIGHT = 500;   // 窗口高度

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
char gameResult[256] = "";                 // 游戏结束时的结果文字

HINSTANCE g_hInstance = NULL;              // 当前程序实例句柄

/* ---------------- 按钮 ---------------- */
struct Button {
    int x, y, width, height;
    const char *text;
};

Button buttons[BUTTON_COUNT];

// 创建全部按钮（棋盘下沿 y = 310，按钮从 y = 330 开始，避免重叠）
void createButtons() {
    // 功能按钮
    buttons[0] = {50, 330, 100, 30, "查看信息"};
    buttons[1] = {160, 330, 100, 30, "使用技能"};
    buttons[2] = {270, 330, 100, 30, "移动棋子"};
    buttons[3] = {380, 330, 100, 30, "结束回合"};

    // 技能按钮
    buttons[4] = {50, 375, 100, 30, "加E"};
    buttons[5] = {160, 375, 100, 30, "求逆"};
    buttons[6] = {270, 375, 100, 30, "转置"};
    buttons[7] = {380, 375, 100, 30, "对角化"};
    buttons[8] = {490, 375, 100, 30, "减E"};

    // 其他按钮
    buttons[9] = {600, 330, 100, 30, "结束游戏"};
    buttons[10] = {710, 330, 100, 30, "查看规则"};
}

// 判断按钮在当前状态下是否可见（技能按钮只在“使用技能”状态显示）
bool isButtonVisible(int index) {
    if (index >= 4 && index <= 8) {
        return gameState == USING_SKILL;
    }
    return true;
}

/* ---------------- 游戏逻辑 ---------------- */
// 结束当前回合：切换玩家、清空选择
void endTurn() {
    currentPlayer = 3 - currentPlayer;
    gameState = SELECTING;
    selectedRow = -1;
    selectedCol = -1;
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
    for (int i = 1; i <= BOARD_SIZE; ++i) {
        for (int j = 1; j <= BOARD_SIZE; ++j) {
            if (amap[i][j] >= 1 && amap[i][j] <= PLAYER1_LAST_ID) {
                ++player1Count;
            } else if (amap[i][j] > PLAYER1_LAST_ID && amap[i][j] <= PIECE_COUNT) {
                ++player2Count;
            }
        }
    }
}

// 初始化游戏
void initGame() {
    // 初始化技能：双方都可使用 1~5 号技能
    for (int i = 1; i <= 5; ++i) {
        jineng[i][1] = true;
        jineng[i][2] = true;
    }

    // 初始化棋盘为空
    for (int i = 1; i <= BOARD_SIZE; ++i) {
        for (int j = 1; j <= BOARD_SIZE; ++j) {
            amap[i][j] = -1;
        }
    }

    // 玩家 1 的棋子：1~10，初始位于上方两行
    for (int i = 1; i <= 2; ++i) {
        for (int j = 1; j <= BOARD_SIZE; ++j) {
            amap[i][j] = (i - 1) * BOARD_SIZE + j;
        }
    }

    // 玩家 2 的棋子：11~20，初始位于下方两行
    for (int i = 4; i <= 5; ++i) {
        for (int j = 1; j <= BOARD_SIZE; ++j) {
            amap[i][j] = (i - 3) * BOARD_SIZE + j + 5;
        }
    }

    // 初始化单位矩阵 E
    for (int i = 1; i <= MATRIX_SIZE; ++i) {
        for (int j = 1; j <= MATRIX_SIZE; ++j) {
            ee.a[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // 以当前系统时间为随机数种子，保证每局矩阵不同
    srand((unsigned)time(NULL));
    for (int i = 1; i <= PIECE_COUNT; ++i) {
        qizi[i] = Matrix(MATRIX_SIZE);
    }

    gameState = SELECTING;
    currentPlayer = 1;
    selectedRow = -1;
    selectedCol = -1;
    gameResult[0] = '\0';
}

// 判定被动结束：任意一方棋子数少于 3 时，比较 3 号与 18 号的行列式
// 返回 true 表示游戏已结束
bool judgeGameEnd() {
    int player1Count = 0, player2Count = 0;
    countPieces(player1Count, player2Count);
    if (player1Count >= 3 && player2Count >= 3) {
        return false;
    }

    double det3 = qizi[3].hanglieshi();
    double det18 = qizi[18].hanglieshi();
    if (det3 > det18) {
        sprintf(gameResult, "游戏结束：玩家 1 获胜\r\n棋子 3 的行列式 %.2f > 棋子 18 的 %.2f", det3, det18);
    } else if (det3 < det18) {
        sprintf(gameResult, "游戏结束：玩家 2 获胜\r\n棋子 18 的行列式 %.2f > 棋子 3 的 %.2f", det18, det3);
    } else {
        sprintf(gameResult, "游戏结束：平局\r\n棋子 3 与棋子 18 的行列式均为 %.2f", det3);
    }
    gameState = GAME_OVER;
    return true;
}

/* ---------------- 绘图 ---------------- */
// 绘制按钮（GDI）
void drawButtons(HDC hdc) {
    for (int i = 0; i < BUTTON_COUNT; ++i) {
        if (!isButtonVisible(i)) {
            continue;
        }
        const Button &btn = buttons[i];

        RECT rect;
        rect.left = btn.x;
        rect.top = btn.y;
        rect.right = btn.x + btn.width;
        rect.bottom = btn.y + btn.height;

        HBRUSH brush = CreateSolidBrush(RGB(200, 200, 255));
        FillRect(hdc, &rect, brush);
        DeleteObject(brush);

        HPEN pen = CreatePen(PS_SOLID, 2, RGB(0, 0, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, pen);
        Rectangle(hdc, btn.x, btn.y, btn.x + btn.width, btn.y + btn.height);
        SelectObject(hdc, oldPen);
        DeleteObject(pen);

        SetBkMode(hdc, TRANSPARENT);
        TextOut(hdc, btn.x + 10, btn.y + 8, btn.text, (int)strlen(btn.text));
    }
}

// 绘制整个游戏界面
void drawGame(HDC hdc, HWND hwnd) {
    RECT clientRect;
    GetClientRect(hwnd, &clientRect);

    HBRUSH bgBrush = CreateSolidBrush(RGB(240, 240, 240));
    FillRect(hdc, &clientRect, bgBrush);
    DeleteObject(bgBrush);

    SetBkMode(hdc, TRANSPARENT);
    SetTextColor(hdc, RGB(0, 0, 0));

    // 标题
    HFONT titleFont = CreateFont(24, 0, 0, 0, FW_BOLD, FALSE, FALSE, FALSE, DEFAULT_CHARSET,
                                 OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
                                 DEFAULT_PITCH | FF_DONTCARE, "Arial");
    HFONT oldFont = (HFONT)SelectObject(hdc, titleFont);
    TextOut(hdc, 200, 10, "矩阵对战游戏", (int)strlen("矩阵对战游戏"));
    SelectObject(hdc, oldFont);
    DeleteObject(titleFont);

    // 当前玩家
    char playerInfo[50];
    sprintf(playerInfo, "当前玩家: %s", currentPlayer == 1 ? "玩家1" : "玩家2");
    TextOut(hdc, 20, 10, playerInfo, (int)strlen(playerInfo));

    // 游戏状态
    const char *stateText = "";
    switch (gameState) {
    case SELECTING:   stateText = "状态: 选择棋子"; break;
    case MOVING:      stateText = "状态: 移动棋子"; break;
    case USING_SKILL: stateText = "状态: 使用技能"; break;
    case GAME_OVER:   stateText = "状态: 游戏结束"; break;
    }
    TextOut(hdc, 20, 40, stateText, (int)strlen(stateText));

    // 棋盘
    for (int i = 1; i <= BOARD_SIZE; ++i) {
        for (int j = 1; j <= BOARD_SIZE; ++j) {
            int x = (j - 1) * CELL_SIZE + BOARD_X;
            int y = (i - 1) * CELL_SIZE + BOARD_Y;

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

            HPEN pen = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));
            HPEN oldPen = (HPEN)SelectObject(hdc, pen);
            Rectangle(hdc, x, y, x + CELL_SIZE, y + CELL_SIZE);
            SelectObject(hdc, oldPen);
            DeleteObject(pen);

            // 棋子编号
            if (amap[i][j] != -1) {
                char buffer[10];
                sprintf(buffer, "%d", amap[i][j]);
                TextOut(hdc, x + CELL_SIZE / 2 - 5, y + CELL_SIZE / 2 - 8, buffer, (int)strlen(buffer));
            }
        }
    }

    drawButtons(hdc);

    // 选中棋子的信息
    if (selectedRow != -1 && selectedCol != -1 && amap[selectedRow][selectedCol] != -1) {
        int id = amap[selectedRow][selectedCol];
        char info[100];
        sprintf(info, "选中棋子: %d", id);
        TextOut(hdc, 350, 60, info, (int)strlen(info));
        sprintf(info, "行列式: %.2f", qizi[id].hanglieshi());
        TextOut(hdc, 350, 80, info, (int)strlen(info));
        sprintf(info, "秩: %d", qizi[id].zhi());
        TextOut(hdc, 350, 100, info, (int)strlen(info));
    }

    // 游戏结束提示
    if (gameState == GAME_OVER && gameResult[0] != '\0') {
        RECT box;
        box.left = BOARD_X;
        box.top = BOARD_Y + 70;
        box.right = BOARD_X + BOARD_SIZE * CELL_SIZE;
        box.bottom = box.top + 110;

        HBRUSH white = CreateSolidBrush(RGB(255, 255, 255));
        FillRect(hdc, &box, white);
        DeleteObject(white);
        FrameRect(hdc, &box, (HBRUSH)GetStockObject(BLACK_BRUSH));

        RECT textRect = {box.left + 10, box.top + 10, box.right - 10, box.bottom - 10};
        SetTextColor(hdc, RGB(180, 0, 0));
        DrawTextA(hdc, gameResult, -1, &textRect, DT_CENTER | DT_WORDBREAK | DT_EDITCONTROL);
        SetTextColor(hdc, RGB(0, 0, 0));
    }
}

/* ---------------- 交互逻辑 ---------------- */
// 弹出选中棋子的矩阵信息
void showMatrixInfo(HWND hwnd, int row, int col) {
    int pieceId = amap[row][col];
    const Matrix &matrix = qizi[pieceId];

    char title[50];
    sprintf(title, "棋子 %d 的矩阵信息", pieceId);

    char info[1000] = "";
    char buffer[200];
    strcat(info, "矩阵:\n");
    for (int i = 1; i <= MATRIX_SIZE; ++i) {
        for (int j = 1; j <= MATRIX_SIZE; ++j) {
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

    // 只能直线移动，且不能原地不动
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

    // 先判定是否被动结束；结束后不再切换回合，避免把“游戏结束”覆盖掉
    if (judgeGameEnd()) {
        return;
    }
    endTurn();
}

// 使用技能
void useSkill(int skill, int row, int col, HWND hwnd) {
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
        // 求逆失败时不消耗技能，也不结束回合
        if (!qizi[pieceId].fuzhini()) {
            MessageBox(hwnd, "该棋子矩阵不可逆，求逆失败，技能未消耗。", "提示",
                       MB_OK | MB_ICONWARNING);
            return;
        }
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

    // 标记技能已使用并结束回合
    jineng[skill][currentPlayer] = false;
    endTurn();
}

/* ---------------- 规则窗口 ---------------- */
// 读取规则文本：优先读取程序所在目录的 rules.txt，其次读取当前目录
void loadRulesText(char *buffer, int size) {
    buffer[0] = '\0';

    char path[MAX_PATH] = "";
    if (GetModuleFileNameA(g_hInstance, path, MAX_PATH) > 0) {
        char *slash = strrchr(path, '\\');
        if (slash) {
            *(slash + 1) = '\0';
            strcat(path, "rules.txt");
        }
    }

    FILE *file = NULL;
    if (path[0] != '\0') {
        file = fopen(path, "rb");
    }
    if (!file) {
        file = fopen("rules.txt", "rb");
    }
    if (file) {
        size_t len = fread(buffer, 1, size - 1, file);
        buffer[len] = '\0';
        fclose(file);
    } else {
        strcpy(buffer, "未找到 rules.txt，请把它与程序放在同一目录。");
    }
}

LRESULT CALLBACK RulesWindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);

        static char rules[4096];
        loadRulesText(rules, sizeof(rules));

        RECT rect;
        GetClientRect(hwnd, &rect);
        rect.left += 12;
        rect.top += 12;
        rect.right -= 12;
        SetBkMode(hdc, TRANSPARENT);
        DrawTextA(hdc, rules, -1, &rect, DT_LEFT | DT_WORDBREAK);

        EndPaint(hwnd, &ps);
        break;
    }
    default:
        // 关闭规则窗口只销毁这个窗口，不退出整个程序
        return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

// 打开规则窗口（窗口类已在 WinMain 中注册）
void openRulesWindow(HWND hwnd) {
    HWND rulesHwnd = CreateWindowEx(0, "RulesWindowClass", "游戏规则", WS_OVERLAPPEDWINDOW,
                                    CW_USEDEFAULT, CW_USEDEFAULT, 420, 320,
                                    hwnd, NULL, g_hInstance, NULL);
    if (rulesHwnd) {
        ShowWindow(rulesHwnd, SW_SHOW);
        UpdateWindow(rulesHwnd);
    } else {
        MessageBox(hwnd, "创建规则窗口失败!", "错误", MB_OK | MB_ICONERROR);
    }
}

/* ---------------- 窗口过程 ---------------- */
// 处理按钮点击
void handleButtonClick(int index, HWND hwnd) {
    // 游戏结束后只允许查看规则
    if (gameState == GAME_OVER && index != 10) {
        return;
    }

    switch (index) {
    case 0:  // 查看信息
        if (selectedRow == -1 || selectedCol == -1 || amap[selectedRow][selectedCol] == -1) {
            MessageBox(hwnd, "请先选择一个棋子!", "提示", MB_OK | MB_ICONINFORMATION);
            return;
        }
        showMatrixInfo(hwnd, selectedRow, selectedCol);
        break;

    case 1:  // 使用技能
        gameState = USING_SKILL;
        break;

    case 2:  // 移动棋子
        if (selectedRow == -1 || selectedCol == -1 || amap[selectedRow][selectedCol] == -1) {
            MessageBox(hwnd, "请先选择一个棋子!", "提示", MB_OK | MB_ICONINFORMATION);
            return;
        }
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
        if (selectedRow == -1 || selectedCol == -1 || amap[selectedRow][selectedCol] == -1) {
            MessageBox(hwnd, "请先选择一个棋子!", "提示", MB_OK | MB_ICONINFORMATION);
            return;
        }
        useSkill(index - 3, selectedRow, selectedCol, hwnd);
        break;

    case 9: {  // 结束游戏：按剩余棋子数判胜负
        int player1Count = 0, player2Count = 0;
        countPieces(player1Count, player2Count);
        if (player1Count > player2Count) {
            sprintf(gameResult, "游戏结束：玩家 1 获胜\r\n剩余棋子 玩家1 %d : %d 玩家2",
                    player1Count, player2Count);
        } else if (player1Count < player2Count) {
            sprintf(gameResult, "游戏结束：玩家 2 获胜\r\n剩余棋子 玩家1 %d : %d 玩家2",
                    player1Count, player2Count);
        } else {
            sprintf(gameResult, "游戏结束：平局\r\n剩余棋子 玩家1 %d : %d 玩家2",
                    player1Count, player2Count);
        }
        gameState = GAME_OVER;
        break;
    }

    case 10:  // 查看规则
        openRulesWindow(hwnd);
        break;
    }
}

// 处理棋盘点击
void handleBoardClick(int row, int col, HWND hwnd) {
    if (gameState == SELECTING || gameState == USING_SKILL) {
        selectedRow = row;
        selectedCol = col;
    } else if (gameState == MOVING) {
        if (selectedRow != -1 && selectedCol != -1) {
            int fromRow = selectedRow;
            int fromCol = selectedCol;
            selectedRow = -1;
            selectedCol = -1;
            movePiece(fromRow, fromCol, row, col, hwnd);
        }
    }
}

// 主窗口过程
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
    case WM_CREATE:
        g_hInstance = ((LPCREATESTRUCT)lParam)->hInstance;
        initGame();
        createButtons();
        break;

    case WM_ERASEBKGND:
        return 1;  // 背景由 WM_PAINT 统一绘制，减少闪烁

    case WM_PAINT: {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hwnd, &ps);
        drawGame(hdc, hwnd);
        EndPaint(hwnd, &ps);
        break;
    }

    case WM_LBUTTONDOWN: {
        int x = LOWORD(lParam);
        int y = HIWORD(lParam);

        bool hitButton = false;
        for (int i = 0; i < BUTTON_COUNT; ++i) {
            if (!isButtonVisible(i)) {
                continue;
            }
            const Button &btn = buttons[i];
            if (x >= btn.x && x <= btn.x + btn.width &&
                y >= btn.y && y <= btn.y + btn.height) {
                handleButtonClick(i, hwnd);
                hitButton = true;
                break;
            }
        }

        // 没有点中按钮时才处理棋盘，避免按钮与棋盘区域同时响应
        if (!hitButton && gameState != GAME_OVER) {
            int boardRight = BOARD_X + BOARD_SIZE * CELL_SIZE;
            int boardBottom = BOARD_Y + BOARD_SIZE * CELL_SIZE;
            if (x >= BOARD_X && x < boardRight && y >= BOARD_Y && y < boardBottom) {
                int col = (x - BOARD_X) / CELL_SIZE + 1;
                int row = (y - BOARD_Y) / CELL_SIZE + 1;
                handleBoardClick(row, col, hwnd);
            }
        }

        InvalidateRect(hwnd, NULL, TRUE);
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
    (void)hPrevInstance;
    (void)szCmdLine;

    const char MAIN_CLASS[] = "MatrixGameClass";
    const char RULES_CLASS[] = "RulesWindowClass";

    WNDCLASS wc = {};
    wc.lpfnWndProc = WndProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = MAIN_CLASS;
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&wc)) {
        return 0;
    }

    WNDCLASS rulesWc = {};
    rulesWc.lpfnWndProc = RulesWindowProc;
    rulesWc.hInstance = hInstance;
    rulesWc.lpszClassName = RULES_CLASS;
    rulesWc.hCursor = LoadCursor(NULL, IDC_ARROW);
    rulesWc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    if (!RegisterClass(&rulesWc)) {
        return 0;
    }

    HWND hwnd = CreateWindowEx(0, MAIN_CLASS, "矩阵对战游戏", WS_OVERLAPPEDWINDOW,
                               CW_USEDEFAULT, CW_USEDEFAULT, WINDOW_WIDTH, WINDOW_HEIGHT,
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
    return (int)msg.wParam;
}
