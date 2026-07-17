#include <bits/stdc++.h>
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
Node* construct(vector<int> &val){
    int i=1,j=2;
    queue<Node*>q;
    Node* root=new Node(val[0]);
    q.push(root);
    while(j<val.size()){
        Node*l=NULL;
        Node*r=NULL;
        if(val[i]!=INT_MIN) l=new Node(val[i]);
        if(val[j]!=INT_MIN) r=new Node(val[j]);
        q.front()->left=l;
        q.front()->right=r;
        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);
        q.pop();
        i+=2;
        j+=2;
    }
    return root;
}
map<int,Node*> top(Node* root){
    map<int,Node*>mp;
    queue<pair<int,Node*>>q;
    q.push({0,root});
    mp[0]=root;
    while(!q.empty()){
        if(q.front().second->left!=NULL){
            q.push({q.front().first-1,q.front().second->left});
        }
        if(q.front().second->right!=NULL){
            q.push({q.front().first+1,q.front().second->right});
        }
        if(mp.find(q.front().first)==mp.end()) mp[q.front().first]=q.front().second;
        q.pop();
    }
    return mp;
}
int main(){
    vector<int> val;
    val={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};
    Node* root=construct(val);
    map<int,Node*>mp=top(root);
    for(auto ele:mp){
        cout<<ele.second->val<<" ";
    }
}