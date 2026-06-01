#include <iostream>
using namespace std;
#include<vector>
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
int level(Node* root){
    if(root==NULL)return 0;
    return 1+max(level(root->left),level(root->right));
}
void leveltraverse(Node* root,int Level, vector<vector<int>>&ans){
    if(root==NULL) return;
    ans[Level-1].push_back(root->val);
    leveltraverse(root->left,Level+1,ans);
    leveltraverse(root->right,Level+1,ans);
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
    int levels=level(a);
    vector<vector<int>>ans;
    for (int i=1;i<=levels;i++){
        vector<int>a;
        ans.push_back(a); 
    }
    leveltraverse(a,1,ans);
    for(int i=0;i<levels;i++){
        for(int j=0;j<ans[i].size();j++) cout<<ans[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}