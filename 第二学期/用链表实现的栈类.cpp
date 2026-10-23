#include<bits/stdc++.h>
using namespace std;
class Stack{
	private:
		struct Node{
			double data;
			Node* next;
		};
	    Node* topNode;
	    int stackSize;
	public:
		void push(const double&n){
			Node* newNode=new Node;
			newNode->data=n;
			newNode->next=topNode;
			topNode=newNode;
			stackSize++;
		}
		void pop(){
			if(!isEmpty()){
			Node* temp=topNode;
			topNode=topNode->next;
			delete temp;
			stackSize--;
			}
		}
		const double &top() const{
			if(!isEmpty()){
				return topNode->data;
			}
			static double dummy=0;
			return dummy;
		}
		bool isEmpty() const{
			return stackSize==0;
		}
		int size() const{
			return stackSize;
		}
		void print()const{
			Node*current=topNode;
			cout<<"Stack (top to bottom):";
			while(current !=0){
				cout<<current->data<<" ";
				current=current->next;
			}
			cout<<endl;
		}
		Stack():topNode(0),stackSize(0){};
		Stack(const double*arr,int n){
			topNode=0;
			stackSize=0;
			for(int i=0;i<n;i++){
				push(arr[i]);
			}
		}
		Stack(const Stack&s){
			topNode=0;
			stackSize=0;
			Node*reversed=0;
			Node*current=s.topNode;
			while(current!=0){
				Node*newNode=new Node;
				newNode->data=current->data;
				newNode->next=reversed;
				reversed=newNode;
				current=current->next;
			}
			current=reversed;
			while(current!=0){
				push(current->data);
				Node*temp=current;
				current=current->next;
				delete temp;
			}
		}
		~Stack(){
			while(!isEmpty()){
				pop();
			}
		}
		
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


