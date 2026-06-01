#include <iostream>
using namespace std;
class ListNode{
public:
    int val;
    ListNode*next;
    ListNode(int val){
        this->val=val;
        this->next=NULL;
    }
};
class Stack{
public:
    ListNode*head;
    int size;
    Stack(){
        head=NULL;
        size=0;
    }
    void push(int val){
        ListNode*NewNode=new ListNode(val);
        NewNode->next=head;
        head=NewNode;
        size++;
    }
    void pop(){
        head=head->next;
        size--;
    }
    int len(){
        return size;
    }
    int top(){
        return head->val;
    }
    void print(ListNode* t){
        if(t==NULL) return;
        print(t->next);
        cout<<t->val<<" ";
    }

    void display(){
        ListNode*temp=head;
        print(temp);
    }
};

int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.pop();
    cout<<st.top();
    st.display();
}