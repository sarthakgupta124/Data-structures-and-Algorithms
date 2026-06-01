#include<iostream>
#include<queue>
using namespace std;
int main(){
    priority_queue<int>pq; //it is the maximum heap
    pq.push(10);
    pq.push(-5);
    pq.push(91);
    pq.push(2);
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<pq.top()<<endl;
    

    //minimum heap
    priority_queue<int,vector<int>,greater<int>>mh;
    mh.push(10);
    mh.push(-5);
    mh.push(91);
    mh.push(2);
    cout<<mh.top()<<endl;
    mh.pop();
    cout<<mh.top()<<endl;
    
}