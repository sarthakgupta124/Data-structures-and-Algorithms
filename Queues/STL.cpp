#include <iostream>
using namespace std;
#include <queue>
#include<stack>
void display(queue<int>&q){
    int si=q.size();
    for(int i=0;i<si;i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    return;
}
void reverse(queue<int>&q){
    stack<int>st;
    int si=q.size();
    for(int i=0;i<si;i++){
        st.push(q.front());
        q.pop();
    }
    for(int i=0;i<si;i++){
        q.push(st.top());
        st.pop();
    }
    return;
}
int main(){
    queue<int>q;
    /*main operations
    pop
    push 
    back
    front->top
    size
    empty-return true if the oueue is empty
    */ 
   q.push(10);
   q.push(20);
   q.push(30);
   q.push(40);
   q.push(50);
   cout<<q.front()<<endl;
   cout<<q.back()<<endl;
   q.pop();
   cout<<"top element poped"<<endl;
   cout<<q.front()<<endl;
   cout<<q.back()<<endl;
   display(q);
   cout<<endl;
   reverse(q);
   display(q);
   cout<<endl;
   
}