#include <iostream>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *prev;
    int size;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class dd
{ // user define data structure
public:
    Node *head;
    Node *tail;
    int size;
    dd()
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
            temp->prev = tail;
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
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insertIndex(int idx, int val){
        if (idx < 0 || idx > size)
            cout << "invalid Index" << endl;
        else if (idx == 0)
            insertHead(val);
        else if (idx == size)
            insertTail(val);
        else{
            Node *t = new Node(val);
            Node *temp = head;
            for (int i = 1; i <= idx - 1; i++){
                temp = temp->next;
            }
            temp->next->prev=t;
            t->next=temp->next;
            t->prev=temp;
            temp->next=t; 

            size++;
        }
    }
    void getElement(int idx)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "wrong index" << endl;
        }
        else
        {
            Node *t = head;
            for (int i = 1; i <= idx; i++)
            {
                t = t->next;
            }
            cout << t->val << endl;
        }
    }
    void deleteAtHead()
    {
        if (size == 0)
            cout << "empty list" << endl;
        else
        {
            head = head->next;
            size--;
        }
    }
    void deleteAtTail()
    {
        if (size == 0)
            cout << "empty list" << endl;
        else{
            tail=tail->prev;
            tail->next=NULL;
            size--;
        }
    }
    void deleteAtindex(int idx){
        if (idx < 0 || idx >= size){
            cout << "invalid index";
        }
        else if (idx == 0)
            deleteAtHead();
        else if (idx == size - 1)
            deleteAtTail();
        else{
            if(idx<size/2){
                Node *temp = head;
                for (int i = 1; i < idx; i++){
                    temp = temp->next;
                }
                temp->next->next->prev=temp;
                temp->next=temp->next->next;
            }
            else{
                Node *temp = tail;
                for (int i = 1; i < size -idx; i++){
                    temp = temp->prev;
                }
                temp->prev->prev->next=temp;
                temp->prev=temp->prev->prev;
            }
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
}
;
void display(Node *head)
{
    while(head!=NULL){
        cout << head->val << " ";
        head = head->next;
    }
}
int main()
{
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    a->next = b;
    b->next = c;
    c->next = d;
    d->prev = c;
    c->prev = b;
    b->prev = a;

    
    dd doublelist;
    doublelist.insertHead(10);
    doublelist.insertHead(20);
    doublelist.insertHead(30);
    doublelist.insertTail(100);
    doublelist.insertTail(1);
    doublelist.insertTail(2);
    doublelist.insertTail(3);
    doublelist.insertTail(4);
    doublelist.insertHead(110);
    doublelist.display();
    doublelist.insertIndex(2,1000);
    doublelist.display(); 
    // doublelist.deleteAtHead();
    // doublelist.display(); 
    // doublelist.deleteAtTail();
    // doublelist.display(); 
    doublelist.deleteAtindex(7);
    doublelist.display(); 
    // doublelist.getElement(3);
}