#include <iostream>
#include <queue>
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
void display(Node*root){
    if(root==NULL){
        return;
    }
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}

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
void makearry(Node*root,vector<int>&a){
    if(root==NULL){
        return;
    }
    makearry(root->right,a);
    a.push_back(root->val);
    makearry(root->left,a);
}
void Makeheap(vector<int>a,Node*&root,int &idx){
    if(root==NULL) return;
    root->val=a[idx];
    idx++;
    Makeheap(a,root->left,idx);
    Makeheap(a,root->right,idx);
}
int main(){
    vector<int> val;
    val={10,5,16,1,8,12,20};
    Node*a=construct(val);
    cout<<endl;
    vector<int> arr;
    makearry(a,arr);
    cout<<"array is:"<<endl;
    for(int i=0;i<arr.size();i++) cout<<arr[i]<<" ";
    cout<<endl;
    display(a);
    cout<<endl;
    int idx=0;
    Makeheap(arr,a,idx);
    display(a);
}