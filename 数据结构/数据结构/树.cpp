#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct node{
    char val;
    node* left;
    node* right;
    node(char c):val(c),left(nullptr),right(nullptr){}
};

class Tree{
private:
    node* root; 
    int total; 
    
    void deleteTree(node* n){
        if(n == nullptr) return;  
        deleteTree(n->left);      
        deleteTree(n->right);     
        delete n;                 
        total--;
    }


    void preOrderHelper(node* n, string& s)const{
        if(n == nullptr) return; 
        s += n->val;             
        preOrderHelper(n->left, s); 
        preOrderHelper(n->right, s);
    }

    void inOrderHelper(node* n, string& s)const{
        if(n == nullptr) return;
        inOrderHelper(n->left, s);   
        s += n->val;                
        inOrderHelper(n->right, s); 
    }

    void postOrderHelper(node* n, string& s)const{
        if(n == nullptr) return;
        postOrderHelper(n->left, s);  
        postOrderHelper(n->right, s); 
        s += n->val;                  
    }

public:
    Tree(){
        root = nullptr;
        total = 0;
    }

    Tree(const string& s){
        root = nullptr;
        total = 0;
        if(s.empty()) return;

        queue<node*> q;
        root = new node(s[0]);
        q.push(root);
        total = 1;

        int idx = 1;
        while(!q.empty() && idx < s.size()){
            node* curr = q.front();
            q.pop();

            if(idx < s.size()){
                if(s[idx] != '#'){ 
                    curr->left = new node(s[idx]);
                    q.push(curr->left);
                    total++;
                }
                idx++;
            }

            if(idx < s.size()){
                if(s[idx] != '#'){
                    curr->right = new node(s[idx]);
                    q.push(curr->right);
                    total++;
                }
                idx++;
            }
        }
    }

    ~Tree(){
        deleteTree(root);
        root = nullptr;   
    }

    string preOrder()const{
        string res;
        preOrderHelper(root, res);  
        return res;
    }

    string inOrder()const{
        string res;
        inOrderHelper(root, res);
        return res;
    }

    string postOrder()const{
        string res;
        postOrderHelper(root, res);
        return res;
    }

    int size()const{
        return total;
    }
};

int main() {
    Tree tree("AB#C##D");  
    
    cout << "节点总数：" << tree.size() << endl; 
    cout << "先根遍历：" << tree.preOrder() << endl;
    cout << "中根遍历：" << tree.inOrder() << endl;  
    cout << "后根遍历：" << tree.postOrder() << endl; 

    return 0;
}


