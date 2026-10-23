#include <iostream>
using namespace std;

#define OK 1
#define ERROR 0
#define OVERFLOW -2
typedef int ElemType;
typedef struct {
    ElemType *elem;
    int length;
    int listsize;
} SqList;

// 初始化顺序表
int InitList(SqList &a, int maxsize) {
    a.elem = new ElemType[maxsize];
    if (!a.elem) return OVERFLOW;  // 内存分配失败
    a.length = 0;
    a.listsize = maxsize;
    return OK;
}

// 在非递减有序顺序表中插入元素x并保持有序性
int Insertx(SqList &a, int x) {
    // 检查顺序表是否已满
    if (a.length >= a.listsize) {
        return ERROR;  // 表满，无法插入
    }
    
    // 查找插入位置
    int i = 0;
    while (i < a.length && a.elem[i] <= x) {
        i++;  // 找到第一个大于x的位置
    }
    
    // 将插入位置及之后的元素向后移动一位
    for (int j = a.length; j > i; j--) {
        a.elem[j] = a.elem[j - 1];
    }
    
    // 插入元素x
    a.elem[i] = x;
    a.length++;  // 表长加1
    
    return OK;
}

// 打印顺序表
void PrintList(SqList a) {
    for (int i = 0; i < a.length; i++) {
        cout << a.elem[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList a;
    InitList(a, 10);
    
    // 初始化一些有序元素
    int elements[] = {2, 4, 6, 8};
    for (int i = 0; i < 4; i++) {
        a.elem[i] = elements[i];
        a.length++;
    }
    
    cout << "插入前: ";
    PrintList(a);
    
    Insertx(a, 5);
    cout << "插入5后: ";
    PrintList(a);
    
    Insertx(a, 1);
    cout << "插入1后: ";
    PrintList(a);
    
    Insertx(a, 9);
    cout << "插入9后: ";
    PrintList(a);
    
    delete[] a.elem;
    return 0;
}
    



