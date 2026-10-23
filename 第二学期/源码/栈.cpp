#include <iostream>

// 单链表结点
struct Node {
    double data;
    Node* next;
};

// 用链表实现的栈，topNode 指向栈顶
class Stack {
private:
    Node* topNode;
    int stackSize;

public:
    Stack();
    Stack(const double* arr, int n);
    Stack(const Stack& s);
    ~Stack();

    void push(const double& n);
    void pop();
    const double& top() const;
    bool isEmpty() const;
    int size() const;
    void print() const;
};

Stack::Stack() {
    topNode = nullptr;
    stackSize = 0;
}

Stack::Stack(const double* arr, int n) {
    topNode = nullptr;
    stackSize = 0;
    for (int i = 0; i < n; i++) {
        push(arr[i]);
    }
}

Stack::Stack(const Stack& s) {
    topNode = nullptr;
    stackSize = 0;
    Node* current = s.topNode;
    Node* newNode;
    Node* tail = nullptr;
    while (current != nullptr) {
        newNode = new Node;
        newNode->data = current->data;
        newNode->next = nullptr;
        if (tail == nullptr) {
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
    while (current != nullptr) {
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
    std::cout << "Stack (top to bottom): ";
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    double arr[] = {1.5, 2.5, 3.5, 4.5};
    Stack s(arr, 4);
    s.print();

    s.push(5.5);
    s.print();
    std::cout << "栈顶元素: " << s.top() << std::endl;
    s.pop();
    std::cout << "弹出后栈顶元素: " << s.top() << std::endl;

    // 拷贝构造：两份栈互不影响
    Stack t(s);
    t.push(9.9);
    std::cout << "原栈: ";
    s.print();
    std::cout << "副本: ";
    t.print();

    return 0;
}
