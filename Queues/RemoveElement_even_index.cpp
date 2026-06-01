#include <iostream>
using namespace std;
#include <queue>
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
    int k=q.size();
    for(int i=0;i<k;i++){
        if(i%2!=0) q.push(q.front());
        q.pop();
    }
    display(q);
    return 0;
}