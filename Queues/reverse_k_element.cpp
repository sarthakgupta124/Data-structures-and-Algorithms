#include <iostream>
using namespace std;
#include <queue>
#include <stack>
void reverse_k(int k,queue<int> &q){
    stack <int> temp;
    for(int i=0;i<k;i++){
        temp.push(q.front());
        q.pop();
    }
    for(int i=0;i<k;i++){
        q.push(temp.top());
        temp.pop();
    }
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }
    return;
    
}
void display(queue<int>&q){
    int si=q.size();
    for(int i=0;i<si;i++){
        cout<<q.front()<<" ";
        q.push(q.front());
        q.pop();
    }
    cout<<endl;
    return;
}
int main(){
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display(q);
    reverse_k(3,q);
    display(q);
}