#include <iostream>

const int MAX_SIZE = 100;

class Stack {
private:
    int arr[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    // 入栈操作
    void push(int value) {
        if (top == MAX_SIZE - 1) {
            std::cout << "栈已满，无法入栈" << std::endl;
            return;
        }
        arr[++top] = value;
    }

    // 出栈操作
    void pop() {
        if (top == -1) {
            std::cout << "栈为空，无法出栈" << std::endl;
            return;
        }
        --top;
    }

    // 查看栈顶元素
    int topElement() {
        if (top == -1) {
            std::cout << "栈为空" << std::endl;
            return -1;
        }
        return arr[top];
    }

    // 判断栈是否为空
    bool empty() {
        return top == -1;
    }

    // 获取栈的大小
    int size() {
        return top + 1;
    }
};

int main() {
    Stack myStack;

    // 入栈操作
    myStack.push(10);
    myStack.push(20);
    myStack.push(30);

    // 查看栈顶元素
    std::cout << "栈顶元素: " << myStack.topElement() << std::endl;

    // 出栈操作
    myStack.pop();

    // 再次查看栈顶元素
    std::cout << "出栈后栈顶元素: " << myStack.topElement() << std::endl;

    // 检查栈是否为空
    if (myStack.empty()) {
        std::cout << "栈为空" << std::endl;
    } else {
        std::cout << "栈不为空，大小为: " << myStack.size() << std::endl;
    }

    return 0;
}

