// ============================================================
// 矩阵类的实现：高斯消元 / 行列式 / 秩 / 转置 / 求逆 / 运算符重载
// 数值判断统一使用 EPS，避免浮点误差带来的误判
// ============================================================
#include "Matrix.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <limits>

using std::swap;

static const double EPS = 1e-9;

// 在 m 的第 col 列中，从第 col 行往下选取绝对值最大的主元
static int choosePivot(double m[MAX_DIM][MAX_DIM], int n, int col) {
    int pivot = col;
    for (int r = col + 1; r <= n; ++r) {
        if (std::fabs(m[r][col]) > std::fabs(m[pivot][col])) {
            pivot = r;
        }
    }
    return pivot;
}

// 部分主元高斯消元：把 m 化为上三角矩阵
static void eliminate(double m[MAX_DIM][MAX_DIM], int n) {
    for (int col = 1; col <= n; ++col) {
        int pivot = choosePivot(m, n, col);
        if (std::fabs(m[pivot][col]) < EPS) {
            continue;  // 该列下方全为 0，跳过
        }
        if (pivot != col) {
            for (int c = 1; c <= n; ++c) {
                swap(m[col][c], m[pivot][c]);
            }
        }
        for (int r = col + 1; r <= n; ++r) {
            if (std::fabs(m[r][col]) < EPS) {
                continue;
            }
            double factor = m[r][col] / m[col][col];
            for (int c = col; c <= n; ++c) {
                m[r][c] -= factor * m[col][c];
            }
            m[r][col] = 0.0;
        }
    }
}

Matrix::Matrix(int nn) : n(nn) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = (double)rand() / RAND_MAX * 10.0;
        }
    }
}

void Matrix::copyTo(double m[MAX_DIM][MAX_DIM]) const {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            m[i][j] = a[i][j];
        }
    }
}

// 行列式：带符号的消元，行交换时符号取反
double Matrix::hanglieshi() const {
    double m[MAX_DIM][MAX_DIM] = {};
    copyTo(m);

    double det = 1.0;
    for (int col = 1; col <= n; ++col) {
        int pivot = choosePivot(m, n, col);
        if (std::fabs(m[pivot][col]) < EPS) {
            return 0.0;  // 存在全零列，行列式为 0
        }
        if (pivot != col) {
            for (int c = 1; c <= n; ++c) {
                swap(m[col][c], m[pivot][c]);
            }
            det = -det;
        }
        det *= m[col][col];
        for (int r = col + 1; r <= n; ++r) {
            if (std::fabs(m[r][col]) < EPS) {
                continue;
            }
            double factor = m[r][col] / m[col][col];
            for (int c = col; c <= n; ++c) {
                m[r][c] -= factor * m[col][c];
            }
            m[r][col] = 0.0;
        }
    }
    return det;
}

// 秩：化为阶梯形后统计非零行的个数
int Matrix::zhi() const {
    double m[MAX_DIM][MAX_DIM] = {};
    copyTo(m);
    eliminate(m, n);

    int rank = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (std::fabs(m[i][j]) >= EPS) {
                ++rank;
                break;
            }
        }
    }
    return rank;
}

void Matrix::zhuanzhi() {
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            swap(a[i][j], a[j][i]);
        }
    }
}

// 高斯消元化为上三角矩阵（“对角化”技能）
void Matrix::fuzhiduijiao() {
    double m[MAX_DIM][MAX_DIM] = {};
    copyTo(m);
    eliminate(m, n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = m[i][j];
        }
    }
}

// 求逆：构造增广矩阵 [A | E]，做高斯-约当消元
bool Matrix::fuzhini() {
    double m[MAX_DIM][2 * MAX_DIM] = {};
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            m[i][j] = a[i][j];
        }
        m[i][n + i] = 1.0;
    }

    const int cols = 2 * n;
    for (int col = 1; col <= n; ++col) {
        // 选主元
        int pivot = col;
        for (int r = col + 1; r <= n; ++r) {
            if (std::fabs(m[r][col]) > std::fabs(m[pivot][col])) {
                pivot = r;
            }
        }
        if (std::fabs(m[pivot][col]) < EPS) {
            return false;  // 不可逆
        }
        if (pivot != col) {
            for (int c = 1; c <= cols; ++c) {
                swap(m[col][c], m[pivot][c]);
            }
        }

        // 主元行归一化
        double d = m[col][col];
        for (int c = 1; c <= cols; ++c) {
            m[col][c] /= d;
        }

        // 消去其他各行的第 col 列
        for (int r = 1; r <= n; ++r) {
            if (r == col || std::fabs(m[r][col]) < EPS) {
                continue;
            }
            double factor = m[r][col];
            for (int c = 1; c <= cols; ++c) {
                m[r][c] -= factor * m[col][c];
            }
            m[r][col] = 0.0;
        }
    }

    // 右半部分即逆矩阵
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            a[i][j] = m[i][n + j];
        }
    }
    return true;
}

Matrix Matrix::operator+(const Matrix &other) const {
    Matrix result(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            result.a[i][j] = a[i][j] + other.a[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
    Matrix result(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            result.a[i][j] = a[i][j] - other.a[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
    Matrix result(n);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            double sum = 0.0;
            for (int k = 1; k <= n; ++k) {
                sum += a[i][k] * other.a[k][j];
            }
            result.a[i][j] = sum;
        }
    }
    return result;
}

// 输入重载：非法输入时提示并重新读取
std::istream &operator>>(std::istream &is, Matrix &m) {
    for (int i = 1; i <= m.n; ++i) {
        for (int j = 1; j <= m.n; ++j) {
            while (!(is >> m.a[i][j])) {
                is.clear();
                is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "输入无效，请再输入一个有效数字: ";
            }
        }
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Matrix &m) {
    for (int i = 1; i <= m.n; ++i) {
        for (int j = 1; j <= m.n; ++j) {
            os << m.a[i][j] << " ";
        }
        os << std::endl;
    }
    return os;
}
