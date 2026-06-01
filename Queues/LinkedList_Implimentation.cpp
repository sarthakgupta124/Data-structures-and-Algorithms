#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Queue{
    Node*head;
    Node*tail;
    int s;
public:
    Queue(){
        s=0;
        head=tail=NULL;
    }
    int size(){
        return s;
    }
    void push(int val){
        Node*temp=new Node(val);
        if(s==0) head=tail=temp;
        else{
            tail->next=temp;
            tail=temp;
        }
        s++;
    }
    void pop(){
        if (s==0){
            cout<<"Oueue is full."<<endl;
            return;
        }
        Node*temp=head;
        head=head->next;
        delete(temp); //save the wastage of the space
        s--;
    }
    int top(){
        if(s==0){
            cout<<"Oueue is empty"<<endl;
            return -1;
        }
        return head->val;
    }
    int back(){
        if(s==0){
            cout<<"Oueue is empty"<<endl;
            return -1;
        }
        return tail->val;
    }
    void display(){
        if(s==0){
            cout<<"Queue is empty.";
            return;
        }
        Node*temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
        return;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display();
    q.push(40);
    q.push(50);
    q.display();
    q.pop();
    q.display();
    cout<<q.top()<<endl<<q.back()<<endl;
    cout<<q.size();
}