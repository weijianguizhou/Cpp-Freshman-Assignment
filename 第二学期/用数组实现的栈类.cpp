#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    T* data;
    int topIndex;
    int capacity;
public:
    // 构造函数
    Stack(int cap);

    // 析构函数
    ~Stack();

    // 压入元素到栈顶
    void push(const T& value);

    // 从栈顶弹出元素
    void pop();

    // 返回栈顶元素的引用
    T& top();

    // 检查栈是否为空
    bool isEmpty() const;

    // 检查栈是否已满
    bool isFull() const;

    // 返回栈中当前元素的数量
    int size() const;
};

// 请实现上述所有方法

// 以下是一个简单的测试程序示例
int main() {
    try {
        Stack<int> stack(5);
        std::cout << "栈是否为空: " << (stack.isEmpty() ? "是" : "否") << std::endl;

        stack.push(10);
        stack.push(20);
        stack.push(30);
        std::cout << "栈顶元素: " << stack.top() << std::endl;
        std::cout << "栈中元素数量: " << stack.size() << std::endl;

        stack.pop();
        std::cout << "弹出一个元素后，栈顶元素: " << stack.top() << std::endl;
        std::cout << "栈是否已满: " << (stack.isFull() ? "是" : "否") << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "异常: " << e.what() << std::endl;
    }

    return 0;
}
template <typename T>
Stack<T>::Stack(int cap){
	capacity=cap;
	topIndex=-1;
}
template <typename T>
Stack<T>::~Stack(){
	while(capacity!=0){
		pop();
	}
}
template <typename T>
void Stack<T>::push(const T& value){
	data[topIndex+1]=value;
}
template <typename T>
void Stack<T>::pop(){
	topIndex--;
}
template <typename T>
T& Stack<T>::top(){
	return(data[topIndex]);
}
template <typename T>
bool Stack<T>::isEmpty()const{
	return (topIndex==-1);
}
template <typename T>
bool Stack<T>::isFull()const{
	return(topIndex==(capacity-1));
}
template <typename T>
int Stack<T>::size()const{
	return topIndex+1;
}


