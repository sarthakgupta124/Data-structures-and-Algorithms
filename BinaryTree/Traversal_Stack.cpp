//traversall iterative method
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
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

vector<int> preorder(Node*root){ 
    stack<Node*>q;
    vector<int>ans;
    q.push(root);
    while(q.size()!=0){
        Node*temp=q.top();
        ans.push_back(temp->val);
        q.pop();
        if(temp->right!=NULL) q.push(temp->right);
        if(temp->left!=NULL) q.push(temp->left);
    }
    return ans;

}
vector<int> inorder(Node*root){ 
    stack<Node*>q;
    vector<int>ans;
    while(true){
        if(root!=NULL){
            q.push(root);
            root=root->left;
        }
        else{
            if(q.empty()) return ans;
            ans.push_back(q.top()->val);
            root=q.top()->right;
            q.pop();
        }
    }

}
vector<int> postorder(Node*root){ 
    stack<Node*>q;
    vector<int>ans;
    q.push(root);
    while(q.size()!=0){
        Node*temp=q.top();
        ans.push_back(temp->val);
        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    reverse(ans.begin(),ans.end());
    return ans;

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
    vector<int>pre;
    pre=preorder(a);
    for(int i=0;i<pre.size();i++){
        cout<<pre[i]<<" ";
    }
    cout<<endl;
    vector<int>post;
    post=postorder(a);
    for(int i=0;i<post.size();i++){
        cout<<post[i]<<" ";
    }

    cout<<endl;
    vector<int>in;
    in=inorder(a);
    for(int i=0;i<in.size();i++){
        cout<<in[i]<<" ";
    }
}