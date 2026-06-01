//traversall using the queue
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
    //root left right 
    cout<<root->val<<" ";
    display(root->left);
    display(root->right);
}
void levelOrderQueue(Node*root){ //BFS
    queue<Node*>q;
    q.push(root);
    while(q.size()!=0){
        Node*temp=q.front();
        cout<<temp->val<<" ";
        q.pop();
        if(temp->left!=NULL) q.push(temp->left);
        if(temp->right!=NULL) q.push(temp->right);
    }
    return;

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
int main(){
    vector<int> val;
    val={1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9,INT_MIN};
    Node*a=construct(val);
    levelOrderQueue(a);
    cout<<endl;
    display(a);

}