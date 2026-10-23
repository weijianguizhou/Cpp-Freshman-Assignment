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
		
		void add(T val){
			Node<T>* newNode=new Node<T>(val);
			if (head == nullptr) {
        		head = newNode;
            	return;
        	}
        	Node<T>* p = head;
        	while (p->next != nullptr) {
            	p = p->next;
        	}
        	p->next = newNode;
    	}
    	
    	void printList() {
        	Node<T>* p = head;
        	while (p != nullptr) {
            	cout << p->data << " ";
            	p = p->next;
        	}
        	cout << endl;
    	}
    	
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
    LinkedList <int>list;
    // 构建测试链表：1->2->3->4->5
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
	list.add(5);
    cout << "逆转前链表：";
    list.printList();
    list.deletedouble();
    list.reverse();

    cout << "逆转后链表：";
    list.printList();

    return 0;
}


