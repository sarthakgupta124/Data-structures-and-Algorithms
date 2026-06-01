#include <iostream>
#include<queue>
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
Node* construct(vector<int>a){
    int i=1,j=2;
    Node* root=new Node(a[0]);
    queue<Node*>q;
    q.push(root);
    while(q.size()!=0 && i<a.size()){
        Node* l;
        Node* r;
        if(a[i]==INT_MIN) l=NULL;
        else {
            l=new Node(a[i]);
            q.push(l);
        }
        if(j<a.size() && a[j]!=INT_MIN) {
            r=new Node(a[j]);
            q.push(r);
        }
        else{
            r=NULL;
        } 
        Node* temp=q.front();
        temp->left=l;
        temp->right=r;
        q.pop();
        i+=2;
        j+=2;
    }
    return root;
}
void si(Node* root,int &s){
    if(root==NULL) return;
    s++;
    si(root->left,s);
    si(root->right,s);
}
bool cbt(Node*root,int size){
    if(root==NULL) return true;
    queue<Node*>q;
    int count=0;
    q.push(root);
    while(count<size){
        if(q.front()!=NULL){
            q.push(q.front()->left);
            q.push(q.front()->right);
        }
        q.pop();
        count++;
    }
    while(!q.empty()){
        if(q.front()!=NULL) return false;
        q.pop();
    }
    return true;
}
void maxHeap(Node*root,bool &check){
    if(root==NULL) return;
    if(root->right!=NULL && root->left!=NULL){
        if(root->val<root->right->val || root->val<root->left->val){
            check=false;
            return;
        }
    }
    else if(root->right!=NULL){
        if(root->val < root->right->val){
            check=false;
            return;
        }
    }
    else if(root->left!=NULL){
        if(root->val < root->left->val){
            check=false;
            return;
        }
    }
    maxHeap(root->left,check);
    maxHeap(root->right,check);
}
int main(){
    vector<int> val;
    val={20,15,10,8,11,INT_MIN,6};
    Node*a=construct(val);
    int size=0;
    si(a,size);
    bool check=true;
    bool ct=cbt(a,size);
    cout<<ct<<endl;
    maxHeap(a,check);
    cout<<check<<endl;
    bool result=check and ct;
    cout<<result;
}