// ============================================================
// 4x4 矩阵类
// 提供高斯消元、行列式、秩、转置、求逆以及常用运算符重载
// ============================================================
#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>

const int MATRIX_SIZE = 4;   // 矩阵默认阶数
const int MAX_DIM = 20;      // 数组最大维度

class Matrix {
public:
    double a[MAX_DIM][MAX_DIM];  // 当前矩阵（下标从 1 开始，到 n 结束）

    // 构造：默认 4 阶，元素在 [0, 10) 内随机生成
    explicit Matrix(int nn = MATRIX_SIZE);

    double hanglieshi() const;  // 行列式
    int zhi() const;            // 秩
    void zhuanzhi();            // 转置，结果写回自身
    void fuzhiduijiao();        // 高斯消元化为上三角，结果写回自身
    bool fuzhini();             // 求逆，成功写回自身并返回 true；不可逆返回 false

    Matrix operator+(const Matrix &other) const;
    Matrix operator-(const Matrix &other) const;
    Matrix operator*(const Matrix &other) const;

    friend std::istream &operator>>(std::istream &is, Matrix &m);
    friend std::ostream &operator<<(std::ostream &os, const Matrix &m);

private:
    int n;  // 阶数

    void copyTo(double m[MAX_DIM][MAX_DIM]) const;  // 把 a 复制到外部数组
};

#endif  // MATRIX_H
