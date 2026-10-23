#include <iostream>
#include <stdexcept>
using namespace std; 
// 定义双向链表节点类模板
template <typename T>
class Node {
public:
    T data;
    Node<T>* prev;
    Node<T>* next;
    Node(const T& value) : data(value), prev(0), next(0) {}
};
// 定义双向链表类模板
template <typename T>
class DoublyLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int listSize;
public:
    // 构造函数
    DoublyLinkedList();
    // 析构函数
    ~DoublyLinkedList();
    // 在链表开头插入元素
    void insertAtBeginning(const T& value);
    // 在链表末尾插入元素
    void insertAtEnd(const T& value);
    // 从链表开头删除元素
    void deleteFromBeginning();
    // 从链表末尾删除元素
    void deleteFromEnd();
    // 正向显示链表元素
    void displayForward() const;
    // 反向显示链表元素
    void displayBackward() const;
    // 检查链表是否为空
    bool isEmpty() const;
    // 返回链表中元素的数量
    int size() const;
};
// 请实现上述所有方法
// 以下是一个简单的测试程序示例
int main() {
    try {
        DoublyLinkedList<int> list;
        std::cout << "链表是否为空: " << (list.isEmpty() ? "是" : "否") << std::endl;

        list.insertAtBeginning(10);
        list.insertAtEnd(20);
        list.insertAtBeginning(5);
        std::cout << "正向显示链表: ";
        list.displayForward();
        std::cout << "反向显示链表: ";
        list.displayBackward();
        std::cout << "链表中元素数量: " << list.size() << std::endl;

        list.deleteFromBeginning();
        std::cout << "删除开头元素后，正向显示链表: ";
        list.displayForward();

        list.deleteFromEnd();
        std::cout << "删除末尾元素后，正向显示链表: ";
        list.displayForward();
    } catch (const std::exception& e) {
        std::cerr << "异常: " << e.what() << std::endl;
    }

    return 0;
}
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(){
	Node<T>* head=0;
	Node<T>* tail=0;
	int listSize=0;
}
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList(){
	while(head!=0){
		Node<T>*temp=head;
		head=head->next;
		delete temp;
	}
}
template <typename T>
void DoublyLinkedList<T>::insertAtBeginning(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    listSize++;
}
template <typename T>
void DoublyLinkedList<T>::insertAtEnd(const T& value){
    Node<T>* newNode = new Node<T>(value);
    if (isEmpty()) {
        head = newNode;
        tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    listSize++;
}
template <typename T>
void DoublyLinkedList<T>::deleteFromBeginning(){
	if (isEmpty()) {
        throw std::runtime_error("链表为空，无法删除元素");
    }
    Node<T>* temp = head;
    if (head == tail) {
        head = 0;
        tail = 0;
    } else {
        head = head->next;
        head->prev = 0;
    }
    delete temp;
    listSize--;
}
template <typename T>
void DoublyLinkedList<T>::deleteFromEnd(){
	if (isEmpty()) {
        throw std::runtime_error("链表为空，无法删除元素");
    }
    Node<T>* temp = tail;
    if (head == tail) {
        head = 0;
        tail = 0;
    } else {
        tail = tail->prev;
        tail->next = 0;
    }
    delete temp;
    listSize--;
}
template <typename T>
void DoublyLinkedList<T>::displayForward() const{
	Node<T>*temp=head;
	for(int i=0;i<listSize;i++){
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}
template <typename T>
void DoublyLinkedList<T>::displayBackward() const{
	Node<T>*temp=tail;
	for(int i=0;i<listSize;i++){
		cout<<temp->data<<" ";
		temp=temp->prev;
	}
	cout<<endl;

}
template <typename T>
bool DoublyLinkedList<T>::isEmpty() const{
	return (listSize==0);
}
template <typename T>
int DoublyLinkedList<T>::size() const{
    return listSize;
}
