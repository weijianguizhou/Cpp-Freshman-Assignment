#include <bits/stdc++.h>
using namespace std;
class Stack {
private:
    struct Node {
        double data;
        Node* next;
    };
    Node* topNode;  // 栈顶节点指针
    int stackSize;   // 栈的大小
public:
    Stack():topNode(0),stackSize(0){};// 默认构造函数  
    Stack(const double *, int);// 用数组初始化的构造函数
    Stack(const Stack& );// 拷贝构造函数
    ~Stack();// 析构函数
    void push(const double &);// 入栈操作
    void pop();// 出栈操作   
    const double & top() const;// 获取栈顶元素  
    bool isEmpty() const;  // 判断栈是否为空
    int size() const;  // 获取栈的大小
    void print() const;  // 打印栈内容
};

int main() {
    double arr[5];
    for(int i=0;i<5;i++) cin>>arr[i];
    Stack s1(arr, 5); //用数组arr构造s1
    s1.print();  
    s1.push(5.6); //入栈
    s1.print();
    cout<<s1.size()<<endl;  //获取s1的大小
    Stack s2(s1);  //用对象s1构造s2
    s2.pop();   //出栈
    s2.print();
    s1.print();
    return 0;
}


