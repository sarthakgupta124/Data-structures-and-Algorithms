//traversall using the queue
#include <iostream>
#include <queue>
#include <climits>
#include<algorithm>
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

int level(Node*root){
    if(root==NULL) return 0;
    return 1+max(level(root->left),level(root->right));
}

void NLevel(Node*root,int Currlevel,int reqLevel){
    if(root==NULL){
        return;
    }
    if(Currlevel==reqLevel){
        cout<<root->val<<" ";
        return;
    } 
    NLevel(root->left,Currlevel+1,reqLevel);
    NLevel(root->right,Currlevel+1,reqLevel);
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

void leftboundary(Node*root,vector<int>&ans){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL) return;
    ans.push_back(root->val);
    leftboundary(root->left,ans);
    if(root->left==NULL) leftboundary(root->right,ans);
}
void midspan(Node*root,vector<int>&ans){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL){
        ans.push_back(root->val);
    }
    midspan(root->left,ans);
    midspan(root->right,ans);
}
void rightboundary(Node*root,vector<int>&ans){
    if(root==NULL) return;
    if(root->left==NULL and root->right==NULL) return ;
    if(root->right==NULL) rightboundary(root->left,ans);
    rightboundary(root->right,ans);
    ans.push_back(root->val);
}
int main(){
    vector<int> val;
    val={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};
    Node*a=construct(val);
    int levels=level(a);
    for(int i=1;i<=levels;i++){
        NLevel(a,1,i);
        cout<<endl;

    }
    vector<int>ans;
    leftboundary(a,ans);
    midspan(a,ans);
    rightboundary(a->right,ans);
    for(int i=0;i<ans.size();i++) cout<<ans[i]<<" ";
    
}