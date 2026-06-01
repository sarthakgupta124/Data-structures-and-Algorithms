#include <iostream>
#include <climits>
using namespace std;
class Node{
public:
    int val;
    Node*left;
    Node*right;
    Node(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;
    }
};

int maxTree(Node*root){
    if(root==NULL) return INT_MIN;
    return max(root->val,max(maxTree(root->left),maxTree(root->right)));
}
int size(Node*root){
    if(root==NULL) return 0;
    return size(root->left)+size(root->right)+1;
}
void display(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
int sumTree(Node*root){
    if(root==NULL) return 0;
    return sumTree(root->left)+sumTree(root->right)+root->val;
}
int level(Node*root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}
int main(){
    Node* a=new Node(1);
    Node* b=new Node(2);
    Node* c=new Node(3);
    Node* d=new Node(4);
    Node* e=new Node(5);
    Node* f=new Node(6);
    Node* g=new Node(7);

    a->left=b;
    a->right=c;
    b->left=d;
    b->right=e;
    c->left=f;
    c->right=g;
    display(a);
    cout<<endl<<sumTree(a);
    cout<<endl<<size(a);
    cout<<endl<<maxTree(a);
    cout<<endl<<level(a);


    return 0;
}