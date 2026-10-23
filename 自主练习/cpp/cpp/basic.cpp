// 邓俊辉《数据结构》向量（Vector）章节代码片段
// 原文件只有各成员函数的实现，缺少 Vector 类定义、Fib 类和主函数，
// 这里补上最小可运行的类框架，使其能独立编译、运行。
#include <iostream>
#include <cstdlib>
#include <algorithm>
using namespace std;

typedef int Rank;          // 秩
#define DEFAULT_CAPACITY 3 // 默认初始容量

// 斐波那契数生成器（原文件由 ..\fibonacci\Fib.h 提供）
class Fib {
private:
    int f, g;
public:
    Fib(int n) {
        f = 1;
        g = 1;
        while (g < n) next(); // 找到不小于 n 的斐波那契数
    }
    int get() const { return g; }
    void next() { int t = g; g += f; f = t; }
    void prev() { int t = f; f = g - f; g = t; }
};

// 向量类：动态数组
template <typename T>
class Vector {
protected:
    Rank _size;   // 当前元素个数
    int _capacity; // 容量
    T* _elem;      // 数据区

    void copyFrom(T const* A, Rank lo, Rank hi) {
        _elem = new T[_capacity = (hi - lo) * 2];
        _size = 0;
        while (lo < hi) {
            _elem[_size++] = A[lo++];
        }
    }

public:
    Vector(int c = DEFAULT_CAPACITY) {
        _elem = new T[_capacity = c];
        _size = 0;
    }

    Vector(T const* A, Rank n) {
        copyFrom(A, 0, n);
    }

    Vector(Vector<T> const& V) {
        copyFrom(V._elem, 0, V._size);
    }

    ~Vector() {
        delete[] _elem;
    }

    Rank size() const { return _size; }
    T* data() const { return _elem; }

    void expand();
    void shrink();
    T& operator[](Rank r) const;
    Rank find(T const& e, Rank lo, Rank hi);
    Rank insert(Rank r, T const& e);
    T remove(Rank r);
    int deduplicate();
};

void bubblesort1A(int arr[], int n) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < n - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
                sorted = false;
            }
        }
        n--;
    }
}

template <typename T> void Vector<T>::expand() {
    if (_size < _capacity) return; // no need to expand
    if (_capacity < DEFAULT_CAPACITY) _capacity = DEFAULT_CAPACITY; // ensure minimum capacity
    T* oldElem = _elem; // keep the old address
    _elem = new T[_capacity <<= 1]; // double the capacity
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i]; // copy old elements
    delete[] oldElem; // free the old space
}

template <typename T> void Vector<T>::shrink() {
    if (_capacity < DEFAULT_CAPACITY << 1) return; // no need to shrink
    if (_size > _capacity >> 2) return; // no need to shrink
    T* oldElem = _elem; // keep the old address
    _elem = new T[_capacity >>= 1]; // halve the capacity
    for (int i = 0; i < _size; i++)
        _elem[i] = oldElem[i]; // copy old elements
    delete[] oldElem; // free the old space
}

template <typename T> T& Vector<T>::operator[](Rank r) const {
    return _elem[r]; // return element at rank r
}

template <typename T> void permute(Vector<T>& V) {
    for (int i = V.size(); i > 0; i--) // from the end to the beginning
        swap(V[i - 1], V[rand() % i]); // swap the last element with a random one among the first i elements
}

template <typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi) {
    while ((lo < hi--) && (e != _elem[hi])); // from the end to the beginning
    return hi; // return the rank of the found element, or lo-1 if not found
}

template <typename T> Rank Vector<T>::insert(Rank r, T const& e) {
    expand(); // ensure space
    for (int i = _size; i > r; i--)
        _elem[i] = _elem[i - 1]; // shift elements to the right
    _elem[r] = e; // insert the new element
    _size++; // increase size
    return r; // return the rank of the inserted element
}

template <typename T> T Vector<T>::remove(Rank r) {
    T e = _elem[r]; // keep the element to be removed
    for (int i = r; i < _size - 1; i++)
        _elem[i] = _elem[i + 1]; // shift elements to the left
    _size--; // decrease size
    shrink(); // ensure space
    return e; // return the removed element
}

template <typename T> int Vector<T>::deduplicate() {
    int oldSize = _size; // keep the old size
    Rank i = 1; // start from the second element
    while (i < _size) // traverse the vector
        (find(_elem[i], 0, i) < 0) ? i++ : remove(i); // if elem[i] is not found in the previous part, move to the next; otherwise, remove it
    return oldSize - _size; // return the number of removed elements
}

// 斐波那契查找，要求 A[lo, hi) 有序
template <typename T> static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi) {
    Fib fib(hi - lo); // create a Fibonacci number generator
    while (lo < hi) {
        while (hi - lo < fib.get()) fib.prev(); // find the largest Fibonacci number less than the range size
        Rank mi = lo + fib.get() - 1; // calculate the mid index
        if (e < A[mi]) hi = mi; // search in the left part
        else if (A[mi] < e) lo = mi + 1; // search in the right part
        else return mi; // element found
    }
    return -1; // element not found
}

int main() {
    // 1. 冒泡排序
    int a[] = {3, 1, 4, 1, 5, 9, 2, 6};
    int n = sizeof(a) / sizeof(a[0]);
    bubblesort1A(a, n);
    cout << "冒泡排序后: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    // 2. 向量基本操作
    Vector<int> v(a, n);
    cout << "向量元素: ";
    for (Rank i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "fibSearch 查找 5 的下标: " << fibSearch(v.data(), 5, 0, v.size()) << endl;
    cout << "fibSearch 查找 8 的下标: " << fibSearch(v.data(), 8, 0, v.size()) << endl;

    v.insert(0, 7);
    v.insert(v.size(), 100);
    cout << "插入 7 和 100 后: ";
    for (Rank i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    cout << "删除下标 2 的元素 " << v.remove(2) << " 后: ";
    for (Rank i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;

    // 3. 去重
    int b[] = {1, 1, 2, 2, 2, 3, 3};
    Vector<int> w(b, 7);
    int removed = w.deduplicate();
    cout << "去重删除 " << removed << " 个元素，剩余: ";
    for (Rank i = 0; i < w.size(); i++) {
        cout << w[i] << " ";
    }
    cout << endl;

    // 4. 随机置乱
    permute(w);
    cout << "随机置乱后: ";
    for (Rank i = 0; i < w.size(); i++) {
        cout << w[i] << " ";
    }
    cout << endl;

    return 0;
}
