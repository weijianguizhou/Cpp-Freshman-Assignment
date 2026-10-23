#include<bits/stdc++.h>
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

Stack::Stack(const double* arr, int n) {
    topNode = 0;
    stackSize = 0;
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
}
Stack::Stack(const Stack& s) {
    topNode = 0;
    stackSize = 0;
    Node* current = s.topNode;
    Node* newNode;
    Node* tail = 0;
    while (current != 0) {
        newNode = new Node;
        newNode->data = current->data;
        newNode->next = 0;
        if (tail == 0) {
            topNode = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        current = current->next;
        stackSize++;
    }
}
Stack::~Stack() {
    Node* current = topNode;
    Node* next;
    while (current != 0) {
        next = current->next;
        delete current;
        current = next;
    }
    stackSize = 0;
}
void Stack::push(const double& n) {
    Node* newNode = new Node;
    newNode->data = n;
    newNode->next = topNode;
    topNode = newNode;
    stackSize++;
}
void Stack::pop() {
    if (!isEmpty()) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
        stackSize--;
    }
}
const double& Stack::top() const {
    if (!isEmpty()) {
        return topNode->data;
    }
    static double dummy = 0;
    return dummy;
}
bool Stack::isEmpty() const {
    return stackSize == 0;
}
int Stack::size() const {
    return stackSize;
}
void Stack::print() const {
    Node* current = topNode;
    cout << "Stack (top to bottom): ";
    while (current != 0) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << std::endl;
}
