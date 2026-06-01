#include <iostream>
using namespace std;

class Node{  //Linked List Node 
public:
    int val;
    Node* next;
    Node(int val){         //constructor
        this->val=val;
        this->next=NULL;
    }
};
void display(Node* head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    display(head->next);

}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    a->next=b;
    b->next=c;
    c->next=d;
    Node*temp=a;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
    //using recursion
    display(a);

}

    