#include <iostream>
#include <queue>
#include <climits>
#include <map>
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


void Topview(Node*root,map<int,Node*> &m,queue<pair<int,Node*>>&q){
    q.push(make_pair(0,root));
    while(!q.empty()){
        if(q.front().second->left!=NULL) q.push(make_pair(q.front().first-1,q.front().second->left));
        if(q.front().second->right!=NULL)q.push(make_pair(q.front().first+1,q.front().second->right));
        if(m.find(q.front().first)==m.end()){
            m.insert(q.front());
        }
        q.pop();
    }   
    return;
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
    queue<pair<int,Node*>> q;
    map<int,Node*>m;
    
    Topview(a,m,q);

    for(auto ele:m){
        cout<<ele.second->val<<" ";
    }
    return 0;
}