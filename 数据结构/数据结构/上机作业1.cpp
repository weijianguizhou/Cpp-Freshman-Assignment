#include<bits/stdc++.h>
using namespace std;

struct Node{
	double num;//coefficient
	int power;//exponent
	Node* next;

	Node(){
		num=0;
		power=0;
		next=nullptr;
	}
};

class poly{
	private:
		Node* head;

		void insert(double num, int power){
            if(num==0) return;

            Node* newNode=new Node();
            newNode->num=num;
            newNode->power=power;
            newNode->next=nullptr;

            if(!head || head->power < power){
                newNode->next = head;
                head = newNode;
                return;
            }

            Node* p = head;
            Node* prev = nullptr;

            while(p && p->power > power){
                prev = p;
                p = p->next;
            }

            if(p && p->power == power){
            
                p->num += num;
                delete newNode;
                
                if(fabs(p->num) < 1e-12){
                    if(prev) prev->next = p->next;
                    else head = p->next;
                    delete p;
                }
            } else {
            
                if(prev){
                    prev->next = newNode;
                    newNode->next = p;
                } else {
                 
                    newNode->next = head;
                    head = newNode;
                }
            }
        }
		public:
		poly(){
			head=nullptr;
		}

		poly(double num, int power){
			head=new Node();
			head->num=num;
			head->power=power;
			head->next=nullptr;
		}
		poly (double num[], int power[], int size){
			head=nullptr;
			for(int i=0;i<size;i++){
				insert(num[i], power[i]);
			}
		}
		~poly(){
			Node* p=head;
			while(p){
				Node* temp=p;
				p=p->next;
				delete temp;
			}
		}

		poly operator+(const poly& other){
			poly result;
			Node* p1=head;
			Node* p2=other.head;

			while(p1){
				result.insert(p1->num, p1->power);
				p1=p1->next;
			}
			while(p2){
				result.insert(p2->num, p2->power);
				p2=p2->next;
			}
			return result;
		}

		void print(){
			Node* p=head;
			bool first=true;
			while(p){
				if(!first && p->num>0) cout<<"+";
				cout<<p->num;
				if(p->power!=0) cout<<"x^"<<p->power;
				first=false;
				p=p->next;
			}
			cout<<endl;
		}


};
int main() {
    // duoxiangshi1: 3x^2 + 5x + 7
    double coefs1[] = {3, 5, 7};
    int exps1[] = {2, 1, 0};
    
    // duoxiangshi2: 2x^3 + 4x^2 - 5x + 1
    double coefs2[] = {2, 4, -5, 1};
    int exps2[] = {3, 2, 1, 0};
    
    poly p1(coefs1, exps1, 3);
    poly p2(coefs2, exps2, 4);
    
    cout << "duoxiangshi1: ";
    p1.print();
    
    cout << "duoxiangshi2: ";
    p2.print();
    
    poly p3 = p1 + p2;
    cout << "p1 + p2 = ";
    p3.print(); 
    
    return 0;
}
