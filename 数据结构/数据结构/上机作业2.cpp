#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
private:
    Node* head;
    int length;
public:
    LinkedList() : head(nullptr) {}

    LinkedList(const int* arr, int size){
        head = nullptr;
        length = 0;
        for (int i = size - 1; i >= 0; --i) {
            Node* newNode = new Node(arr[i]);
            newNode->next = head;
            head = newNode;
            length++;
        }
    }

    ~LinkedList() {
        while (head) {
            Node* temp= head;
            head = head->next;
            delete temp;
            length--;
        }
    }

    void reverse(){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;
        while (current != nullptr) {
            next = current->next; // Store next node
            current->next = prev; // Reverse current node's pointer
            prev = current;       // Move pointers one position ahead
            current = next;
        }
        head = prev; // Update head to new first element
    }

    void printList()  {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

};

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    LinkedList list(arr, 5);
    
    cout << "Original List: ";
    list.printList();
    
    list.reverse();
    
    cout << "Reversed List: ";
    list.printList();
    
    return 0;
}
