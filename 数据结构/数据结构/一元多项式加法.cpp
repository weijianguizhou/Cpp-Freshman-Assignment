#include <iostream>
using namespace std;

// 多项式项的节点结构
template <typename T>
struct PolyNode {
    T coef;          // 系数
    int exp;         // 指数
    PolyNode<T>* next; // 指向下一项
    
    PolyNode(T c, int e) : coef(c), exp(e), next(nullptr) {}
};

// 多项式类
template <typename T>
class Polynomial {
private:
    PolyNode<T>* head;  // 头指针
    
    // 辅助函数：插入项到链表
    void insert(T coef, int exp) {
        if (coef == 0) return; // 系数为0的项不存储
        
        PolyNode<T>* newNode = new PolyNode<T>(coef, exp);
        PolyNode<T>* p = head;
        PolyNode<T>* prev = nullptr;
        
        // 找到插入位置（按指数降序排列）
        while (p && p->exp > exp) {
            prev = p;
            p = p->next;
        }
        
        // 处理指数相同的情况（合并同类项）
        if (p && p->exp == exp) {
            p->coef += coef;
            if (p->coef == 0) { // 合并后系数为0则删除该节点
                if (prev) prev->next = p->next;
                else head = p->next;
                delete p;
            }
            delete newNode; // 释放新建节点
        } else {
            // 插入新节点
            newNode->next = p;
            if (prev) prev->next = newNode;
            else head = newNode;
        }
    }

public:
    // 构造函数
    Polynomial() : head(nullptr) {}
    
    // 从系数和指数数组创建多项式
    Polynomial(T coefs[], int exps[], int n) : head(nullptr) {
        for (int i = 0; i < n; i++) {
            insert(coefs[i], exps[i]);
        }
    }
    
    // 析构函数
    ~Polynomial() {
        PolyNode<T>* p;
        while (head) {
            p = head;
            head = head->next;
            delete p;
        }
    }
    
    // 多项式加法
    Polynomial<T> operator+(const Polynomial<T>& other) const {
        Polynomial<T> result;
        PolyNode<T>* p1 = head;
        PolyNode<T>* p2 = other.head;
        
        // 合并两个多项式
        while (p1 && p2) {
            if (p1->exp > p2->exp) {
                result.insert(p1->coef, p1->exp);
                p1 = p1->next;
            } else if (p1->exp < p2->exp) {
                result.insert(p2->coef, p2->exp);
                p2 = p2->next;
            } else {
                // 指数相同，系数相加
                result.insert(p1->coef + p2->coef, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        
        // 处理剩余项
        while (p1) {
            result.insert(p1->coef, p1->exp);
            p1 = p1->next;
        }
        while (p2) {
            result.insert(p2->coef, p2->exp);
            p2 = p2->next;
        }
        
        return result;
    }
    
    // 输出多项式
    void print() const {
        if (!head) {
            cout << "0" << endl;
            return;
        }
        
        PolyNode<T>* p = head;
        bool firstTerm = true;
        
        while (p) {
            // 处理符号
            if (firstTerm) {
                if (p->coef < 0) cout << "-";
                firstTerm = false;
            } else {
                if (p->coef > 0) cout << "+";
                else cout << "-";
            }
            
            T absCoef = abs(p->coef);
            // 处理系数
            if (absCoef != 1 || p->exp == 0) {
                cout << absCoef;
            }
            
            // 处理指数
            if (p->exp > 0) {
                cout << "x";
                if (p->exp > 1) {
                    cout << "^" << p->exp;
                }
            }
            
            p = p->next;
        }
        cout << endl;
    }
};

int main() {
    // 示例1: 3x^2 + 5x + 7
    int coefs1[] = {3, 5, 7};
    int exps1[] = {2, 1, 0};
    
    // 示例2: 2x^3 + 4x^2 - 5x + 1
    int coefs2[] = {2, 4, -5, 1};
    int exps2[] = {3, 2, 1, 0};
    
    Polynomial<int> p1(coefs1, exps1, 3);
    Polynomial<int> p2(coefs2, exps2, 4);
    
    cout << "多项式p1: ";
    p1.print();
    
    cout << "多项式p2: ";
    p2.print();
    
    Polynomial<int> p3 = p1 + p2;
    cout << "p1 + p2 = ";
    p3.print(); // 结果应为: 2x^3 + 7x^2 + 8
    
    return 0;
}


