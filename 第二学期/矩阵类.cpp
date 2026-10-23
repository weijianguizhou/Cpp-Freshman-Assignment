#include<bits/stdc++.h>
using namespace std;
class Matrix{
private:
    int x;
    int y;
    int** l;

public:
    Matrix(int a = 1, int b = 1, int c = 0){
        x = a;
        y = b;
        l = new int*[x];
        for(int i = 0; i < x; i++){
            l[i] = new int[y];
            for(int j = 0; j < y; j++){
                l[i][j] = c;
            }
        }
    }
    Matrix(const Matrix &m){
        x = m.x;
        y = m.y;
        l = new int*[x];
        for(int i = 0; i < x; i++){
            l[i] = new int[y];
            for(int j = 0; j < y; j++){
                l[i][j] = m.l[i][j];
            }
        }
    }
    ~Matrix(){
        for(int i = 0; i < x; i++){
            delete[] l[i];
        }
        delete[] l;
    }
    Matrix operator+(const Matrix &m) const{
        if(x != m.x || y != m.y){
            cout << "Error" << endl;
            return Matrix(); 
        }
        Matrix d(x, y);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                d.l[i][j] = l[i][j] + m.l[i][j];
            }
        }
        return d;
    }
    Matrix operator-(const Matrix &m) const{
        if(x != m.x || y != m.y){
            cout << "Error" << endl;
            return Matrix();
        }
        Matrix d(x, y);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < y; j++){
                d.l[i][j] = l[i][j] - m.l[i][j];
            }
        }
        return d;
    }
    Matrix operator*(const Matrix &m) const{
        if(y != m.x){
            cout << "Error" << endl;
            return Matrix();
        }
        Matrix d(x, m.y);
        for(int i = 0; i < x; i++){
            for(int j = 0; j < m.y; j++){
                d.l[i][j] = 0;
                for(int k = 0; k < y; k++){
                    d.l[i][j] += l[i][k] * m.l[k][j];
                }
            }
        }
        return d;
    }
    int getx() const{
        return x;
    }
    int gety() const{
        return y;
    }
    Matrix& operator=(const Matrix &m){
        if (this != &m) {
            for(int i = 0; i < x; i++){
                delete[] l[i];
            }
            delete[] l;
            x = m.x;
            y = m.y;
            l = new int*[x];
            for(int i = 0; i < x; i++){
                l[i] = new int[y];
                for(int j = 0; j < y; j++){
                    l[i][j] = m.l[i][j];
                }
            }
        }
        return *this;
    }
    bool operator!=(const Matrix &m) const {
        if (x != m.x || y != m.y) {
            return true;
        }
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                if (l[i][j] != m.l[i][j]) {
                    return true;
                }
            }
        }
        return false;
    }
    friend ostream& operator<<(ostream& os, const Matrix &m){
        for(int i = 0; i < m.getx(); i++){
            for(int j = 0; j < m.gety(); j++){
                os << m.l[i][j] << " ";
            }
            os << endl;
        }
        return os;
    }
    Matrix transpose() const {
        Matrix result(y, x);
        for (int i = 0; i < x; i++) {
            for (int j = 0; j < y; j++) {
                result.l[j][i] = l[i][j];
            }
        }
        return result;
    }
        Matrix inverse() const {
        if (x != y) {
            cout << "Matrix is not square, so it's not invertible." << endl;
            return Matrix();
        }
        int n = x;
        Matrix augmented(n, 2 * n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                augmented.l[i][j] = l[i][j];
            }
            augmented.l[i][i + n] = 1;
        }
        for (int i = 0; i < n; i++) {
            if (augmented.l[i][i] == 0) {
                bool found = false;
                for (int k = i + 1; k < n; k++) {
                    if (augmented.l[k][i] != 0) {
                        for (int j = 0; j < 2 * n; j++) {
                            swap(augmented.l[i][j], augmented.l[k][j]);
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Matrix is not invertible." << endl;
                    return Matrix();
                }
            }
            int pivot = augmented.l[i][i];
            for (int j = 0; j < 2 * n; j++) {
                augmented.l[i][j] /= pivot;
            }
            for (int k = 0; k < n; k++) {
                if (k != i) {
                    int factor = augmented.l[k][i];
                    for (int j = 0; j < 2 * n; j++) {
                        augmented.l[k][j] -= factor * augmented.l[i][j];
                    }
                }
            }
        }
        Matrix inv(n, n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                inv.l[i][j] = augmented.l[i][j + n];
            }
        }
        return inv;
    }
};


int main() {
    Matrix m1(2, 2, 1);
    Matrix m2(2, 2, 2);
    Matrix m3 = m1 + m2;
    cout << m3;
    if (m1 != m2) {
        Matrix m4 = m2 - m1;
        cout << m4;
    }
    return 0;
}



