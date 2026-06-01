#include <iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL;
    }
};
class Deque{
    Node*head;
    Node*tail;
    int s;
public:
    Deque(){
        s=0;
        head=tail=NULL;
    }
    int size(){
        return s;
    }
    void frontpush(int val){
        Node*temp=new Node(val);
        if(s==0) head=tail=temp;
        else{
            head->prev=temp;
            temp->next=head;
            head=temp;
        }
        s++;
    }
    void backpush(int val){
        Node*temp=new Node(val);
        if(s==0) head=tail=temp;
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        s++;
    }
    void frontpop(){
        if (s==0){
            cout<<"Oueue is empty."<<endl;
            return;
        }
        Node*temp=head;
        head=head->next;
        head->prev=NULL;
        delete(temp); //save the wastage of the space
        s--;
    }
    void backpop(){
        if (s==0){
            cout<<"Oueue is empty."<<endl;
            return;
        }
        Node*temp=tail;
        tail=tail->prev;
        tail->next=NULL;
        delete(temp); //save the wastage of the space
        s--;
    }
    int front(){
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
    Deque q;
    q.frontpush(10);
    q.frontpush(20);
    q.frontpush(30);
    q.display();
    q.backpush(40);
    q.backpush(50);
    q.display();
    q.frontpop();
    q.display();
    q.backpop();
    q.display();
    cout<<q.front()<<endl<<q.back()<<endl;
    cout<<q.size();
}