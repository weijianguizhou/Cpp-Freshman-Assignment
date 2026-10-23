#include<bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

class linklist{
private:
    node* head;  // 头指针，假设head指向头结点，头结点不存储数据
    int length;
    
public:
    // 构造函数
    linklist(){
        head = new node;  // 创建头结点
        head->next = nullptr;
        length = 0;
    }
    
    // 拷贝构造函数（深拷贝）
    linklist(const linklist &L){
        head = new node;
        head->next = nullptr;
        length = 0;
        
        node* p = L.head->next;
        node* q = head;
        
        while(p != nullptr){
            node* newNode = new node;
            newNode->data = p->data;
            newNode->next = nullptr;
            q->next = newNode;
            
            q = q->next;
            p = p->next;
            length++;
        }
    }
    
    // 获取元素，成功返回true，失败返回false
    bool GetElem(int i, int &e){
        if(i < 1 || i > length) return false;
        
        node* p = head->next;
        int j = 1;
        while(j < i){
            p = p->next;
            j++;
        }
        e = p->data;
        return true;
    }
    
    // 获取长度
    int Getlength(){
        return length;
    }
    
    // 插入元素
    bool ListInsert(int i, int e){
        if(i < 1 || i > length + 1) return false;
        
        node* p = head;
        int j = 1;
        // 找到第i-1个节点
        while(j < i){
            p = p->next;
            j++;
        }
        
        node* newNode = new node;
        newNode->data = e;
        newNode->next = p->next;
        p->next = newNode;
        length++;
        
        return true;
    }
    
    // 析构函数，释放内存
    ~linklist(){
        node* p = head;
        while(p != nullptr){
            node* q = p;
            p = p->next;
            delete q;
        }
        length = 0;
    }
};
int main(){
	return 0;
}


