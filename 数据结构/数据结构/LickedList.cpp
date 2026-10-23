// 单链表的基本操作：头插法 / 尾插法建表、按位置插入、按位置删除、
// 按值查找、逆置、遍历输出
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int d) : data(d), next(nullptr) {}
};

class LinkList {
private:
    Node* head;

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

public:
    LinkList() : head(nullptr) {}

    LinkList(const LinkList&) = delete;
    LinkList& operator=(const LinkList&) = delete;

    ~LinkList() {
        clear();
    }

    // 尾插法：保持输入顺序
    void createByTail(const int* arr, int n) {
        clear();
        Node* tail = nullptr;
        for (int i = 0; i < n; i++) {
            Node* node = new Node(arr[i]);
            if (head == nullptr) {
                head = node;
            } else {
                tail->next = node;
            }
            tail = node;
        }
    }

    // 头插法：结果与输入顺序相反
    void createByHead(const int* arr, int n) {
        clear();
        for (int i = 0; i < n; i++) {
            Node* node = new Node(arr[i]);
            node->next = head;
            head = node;
        }
    }

    // 在下标 pos 处插入 value，pos 取 0 ~ length
    bool insert(int pos, int value) {
        int len = length();
        if (pos < 0 || pos > len) {
            return false;
        }
        if (pos == 0) {
            Node* node = new Node(value);
            node->next = head;
            head = node;
            return true;
        }
        Node* prev = head;
        for (int i = 0; i < pos - 1; i++) {
            prev = prev->next;
        }
        Node* node = new Node(value);
        node->next = prev->next;
        prev->next = node;
        return true;
    }

    // 删除下标 pos 处的结点
    bool remove(int pos) {
        if (pos < 0 || head == nullptr) {
            return false;
        }
        if (pos == 0) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* prev = head;
        for (int i = 0; i < pos - 1 && prev->next != nullptr; i++) {
            prev = prev->next;
        }
        if (prev->next == nullptr) {
            return false;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        return true;
    }

    // 按值查找，返回下标，找不到返回 -1
    int find(int value) const {
        int pos = 0;
        for (Node* p = head; p != nullptr; p = p->next, pos++) {
            if (p->data == value) {
                return pos;
            }
        }
        return -1;
    }

    // 原地逆置
    void reverse() {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }

    int length() const {
        int len = 0;
        for (Node* p = head; p != nullptr; p = p->next) {
            len++;
        }
        return len;
    }

    void print() const {
        for (Node* p = head; p != nullptr; p = p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }
};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkList list;

    list.createByTail(arr, 5);
    cout << "尾插法建表: ";
    list.print();

    list.createByHead(arr, 5);
    cout << "头插法建表: ";
    list.print();

    list.insert(2, 100);
    cout << "在下标 2 处插入 100: ";
    list.print();

    list.remove(0);
    cout << "删除下标 0 的结点: ";
    list.print();

    cout << "值为 3 的结点下标: " << list.find(3) << endl;
    cout << "结点个数: " << list.length() << endl;

    list.reverse();
    cout << "逆置后: ";
    list.print();

    return 0;
}
