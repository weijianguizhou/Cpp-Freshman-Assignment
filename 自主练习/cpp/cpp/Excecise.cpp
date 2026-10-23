// 顺序表练习：就地逆置、合并两个递增有序表
#include <iostream>
using namespace std;

const int MAXSIZE = 100;

struct SeqList {
    int data[MAXSIZE];
    int length;
};

// 初始化空表
void initList(SeqList& L) {
    L.length = 0;
}

// 在表尾追加元素
bool append(SeqList& L, int x) {
    if (L.length >= MAXSIZE) {
        return false;
    }
    L.data[L.length++] = x;
    return true;
}

// 就地逆置
void reverse(SeqList& L) {
    for (int i = 0, j = L.length - 1; i < j; i++, j--) {
        int t = L.data[i];
        L.data[i] = L.data[j];
        L.data[j] = t;
    }
}

// 把两个递增有序表 A、B 合并成递增有序表 C
bool merge(const SeqList& A, const SeqList& B, SeqList& C) {
    if (A.length + B.length > MAXSIZE) {
        return false;
    }
    initList(C);
    int i = 0, j = 0;
    while (i < A.length && j < B.length) {
        if (A.data[i] <= B.data[j]) {
            append(C, A.data[i++]);
        } else {
            append(C, B.data[j++]);
        }
    }
    while (i < A.length) {
        append(C, A.data[i++]);
    }
    while (j < B.length) {
        append(C, B.data[j++]);
    }
    return true;
}

void print(const SeqList& L) {
    for (int i = 0; i < L.length; i++) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SeqList A, B, C;
    initList(A);
    initList(B);

    int a[] = {1, 3, 5, 7, 9};
    int b[] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; i++) {
        append(A, a[i]);
        append(B, b[i]);
    }

    cout << "表 A: ";
    print(A);
    cout << "表 B: ";
    print(B);

    reverse(A);
    cout << "A 逆置后: ";
    print(A);
    reverse(A);

    merge(A, B, C);
    cout << "合并后的表 C: ";
    print(C);

    return 0;
}
