#include <iostream>
using namespace std;

class Node
{ // Linked List Node  //user define data type
public:
    int val;
    Node *next;
    Node(int val)
    { // constructor
        this->val = val;
        this->next = NULL;
    }
};
class LinkedList
{ // user define data structure
public:
    Node *head;
    Node *tail;
    int size;
    LinkedList()
    {
        head = tail = NULL;
        size = 0;
    }
    void insertTail(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void insertHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head;
            head = temp;
        }
        size++;
    }
    void insertIndex(int idx, int val){
        if (idx < 0 || idx > size) cout << "invalid Index" << endl;
        
        else if (idx == 0)
            insertHead(val);
        else if (idx == size)
            insertTail(val);
        else{
            // int fidx = 0;
            // Node *t = head;
            // while ((++fidx) < idx){
            //     t= t->next;
            // }

            // Node *temp = new Node(val);
            // temp->next = t->next;
            // t->next = temp;
            // size++;

            Node*t =new Node(val);
            Node*temp=head;
            for(int i=1;i<=idx-1;i++){
                temp=temp->next;
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }
    void getElement(int idx){
        if(idx<0 || idx>=size){
            cout<<"wrong index"<<endl;
        }
        else{
            Node*t=head;
            for(int i=1;i<=idx;i++){
                t=t->next;
            }
            cout<<t->val<<endl;
        }
    }
    void deleteAtHead(){
        if(size==0) cout<<"empty list"<<endl;
        else{
            head=head->next;
            size--;
        }
    }
    void deleteAtTail(){
        if(size==0) cout<<"empty list"<<endl;
        else{
            Node*temp=head;
            while(temp->next!=tail){
                temp=temp->next;
            }
            tail=temp;
            tail->next=NULL;
            size--;
        }
    }
    void deleteAtindex(int idx){
        if(idx<0 || idx>=size){
            cout<<"invalid index";
        }
        else if(idx==0) deleteAtHead();
        else if(idx==size-1) deleteAtTail();
        else{
            Node*temp=head;
            for(int i=1;i<idx;i++){
                temp=temp->next;
            }
            temp->next=temp->next->next;
        }
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    LinkedList ll;
    ll.insertTail(10);
    ll.display();
    ll.insertTail(20);
    ll.display();
    ll.insertTail(30);
    ll.display();

    ll.insertHead(0);
    ll.display();
    ll.insertIndex(2, 500);
    ll.display();

    ll.getElement(2);
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();
    ll.deleteAtindex(2);
    ll.display();

}