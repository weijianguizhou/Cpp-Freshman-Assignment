#include<bits/stdc++.h>
using namespace std;
struct Node{
	int data;
	Node *next;
};
struct LinkedList{
	Node *head;
	int size;
};
LinkedList create(){
	LinkedList list;
	list.head=0;
	list.size=0;
	return list;
}//创建一个空链表
LinkedList create(const int a[],int n){
	LinkedList list=create();
	Node *p1,*p2;
	for(int i=0;i<n;i++){
		p1=new Node;
		p1->data=a[i];
		p1->next=NULL;
		if(list.head==0){
			list.head=p1;
		}else{
			p2->next=p1;
			p2=p1;
		}
	}
	list.size=n;
	return list;
}             //以一个数组来初始化一个单链表
void print(const LinkedList &list){
	cout<<"size="<<list.size<<":";
	Node *p=list.head;
	while(p!=NULL){
		cout<<p->data<<'\t';
		p=p->next;
	}
	cout<<"\n";
}            //输出链表上各个结点的值 
void removeAll(LinkedList &list){
	Node *p1;
	while(list.head){
		p1=list.head;
		list.head=list.head->next;
		delete p1;
	}
	list.size=0;
}           //释放链表的结点空间
int search(const LinkedList &list,const int data){
	Node *p=list.head;
	for(int i=0;p!=NULL;i++){
		if(p->data=data)
			return i;
			p=p->next;
	}
	return -1;
}           //在链表中查找指定的data
int remove(LinkedList &list,const int index){
	if(list.size==0||index<0||index>=list.size)
	   throw index;
	if(index==0){
		list.size--;
		Node *p=list.head;
		list.head=list.head->next;
		int a=p->data;
		delete p;
		return a;
	}
	Node *p1=list.head,*p2=p1;
	for(int i=0;i<index;i++){
		p1=p2;
		p2=p2->next;
	}
	list.size--;
	p1->next=p2->next;
	int a=p2->data;
	delete p2;
	return a;
}       //删除指定下标index的结点，并返回被删结点的数据 
LinkedList Delate_one_node(LinkedList list,int num){
	Node *p1,*p2;
	if(list.size==0){
		cout<<"链表为空，无结点可删！\n";
		return list;
	}
	if(list.head->data==num){
		p1=list.head;
		list.head=list.head->next;
		list.size--;
		delete p1;
		cout<<"删除了一个结点！\n";
	}else{
		p2=p1=list.head;
		while(p2->data!=num&&p2->next!=0){
			p1=p2;
			p2=p2->next;
		}
		if(p2->data=num){
			p1->next=p2->next;
			list.size--;
			delete p2;
			cout<<"删除了一个结点！\n";
		}else{
			cout<<num<<"链表上没有要删除的结点!\n";
		}
		return list;
	}
}               //删除链表上具有指定值的一个结点
void insertAsc(LinkedList &list,const int data){
	Node *p=new Node;
	p->data=data;
	list.size++;
	if(list.head==NULL||p->data<=list.head->data){
		p->next=list.head;
		list.head=p;
		return;
	}
	Node *p1=list.head,*p2=p1;
	while(p2!=NULL&&p2->data<p->data){
		p1=p2;
		p2=p2->next;
	}
	p->next=p2;
	p1->next=p; 
}      //结点插入链表，并保持升序关系 
int main(){

	return 0;
}


