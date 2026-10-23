#include <bits/stdc++.h>
using namespace std;

class SqList{
    private:
        int *data;
        int maxSize;
        int length;
    
    public:
        SqList(int size){
            maxSize = size;
            data = new int[maxSize];
            length = 0;
        }
        ~SqList(){
            delete[] data;
        }

        void insert(int value){
            if(length < maxSize){
                length++;
                for(int i = length - 1; i > 0; i--){
                    data[i] = data[i - 1];
                    if(data[i - 1] <= value){
                        data[i] = value;
                        return;
                    }
                }
                data[0] = value;
            }
            if(length == maxSize){
                cout << "List is full!" << endl;
            }
        }
        void display(){
            for(int i = 0; i < length; i++){
                cout << data[i] << " ";
            }
            cout << endl;
        }
    };
int main(){
    SqList list(5);
    list.insert(3);
    list.display();
    list.insert(1);
    list.display(); // Output: 1 3
    list.insert(4);
    list.insert(2);
    list.display(); // Output: 1 2 3 4
    list.insert(5);
    list.display(); // Output: 1 2 3 4 5
    list.insert(6); // Output: List is full!
    return 0;
}
