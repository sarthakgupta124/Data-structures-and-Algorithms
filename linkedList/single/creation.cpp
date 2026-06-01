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
int main(){
    Node a(10);
    // a.val=10;
    Node b(20);
    // b.val=20;
    Node c(30);
    // c.val=30;
    Node d(40);
    // d.val=40;
    //forming linked list
    a.next=&b;
    b.next=&c;
    c.next=&d;
    d.next=NULL;
    // cout<< (*(a.next)).val<<"\n";
    // cout<< (a.next)->val<<endl;
    // cout<< (*((*((*(a.next)).next)).next)).val<<endl;
    // // or
    // cout<<((a.next->next)->next)->val;

    //to print all values with fwhile loop
    Node temp=a;
    while(true){
        cout<<temp.val<<endl;
        if(temp.next==NULL)
            break;
        temp=*(temp.next);
    }
}