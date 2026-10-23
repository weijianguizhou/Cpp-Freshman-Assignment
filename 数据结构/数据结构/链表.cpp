#include<bits/stdc++.h>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node<T>* next;
    Node(const T& value) : data(value), next(0) {}
};

template <typename T>
class LinkedList{
   private:
           Node<T>* head;
           int length;

   public:
           LinkedList(){
                   head=0;
                   length=0;
           }

           LinkedList(T* arr,int num){
                   head=0;
                   length=0;
                   for(int i=0;i<num;i++){
                           add(arr[i]);
                   }
           }

           ~LinkedList(){
                   while(head!=0){
                           Node<T>* temp=head;
                           head=head->next;
                           delete temp;
                   }
           }

           // 原地逆置链表
           void reverse(){
                   Node<T>* prev=0;
                   Node<T>* curr=head;
                   while(curr!=0){
                           Node<T>* next=curr->next;
                           curr->next=prev;
                           prev=curr;
                           curr=next;
                   }
                   head=prev;
           }

           // 尾插法添加元素
           void add(T val){
                   Node<T>* newNode=new Node<T>(val);
                   if (head == nullptr) {
                   head = newNode;
                   length++;
                   return;
           }
           Node<T>* p = head;
           while (p->next != nullptr) {
                   p = p->next;
           }
           p->next = newNode;
           length++;
           }

           void printList() {
           Node<T>* p = head;
           while (p != nullptr) {
                   cout << p->data << " ";
                   p = p->next;
           }
           cout << endl;
           }

           // 删除相邻的重复元素
           void deletedouble() {
                   if (head == nullptr || head->next == nullptr) {
           return;
                   }

                   Node<T>* curr = head;
                   while (curr != nullptr && curr->next != nullptr) {
                   if (curr->data == curr->next->data) {
                           Node<T>* temp = curr->next;
                           curr->next = curr->next->next;
                           delete temp;
                           length--;
                   } else {
                           curr = curr->next;
                   }
                   }
           }

};

int main() {
    int arr[] = {1, 2, 2, 3, 3, 3, 4};
    LinkedList<int> list(arr, 7);

    cout << "链表: ";
    list.printList();

    list.deletedouble();
    cout << "删除相邻重复元素后: ";
    list.printList();

    list.reverse();
    cout << "逆置后: ";
    list.printList();

    list.add(5);
    cout << "尾部添加 5: ";
    list.printList();

    return 0;
}
