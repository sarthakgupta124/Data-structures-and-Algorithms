#include<iostream>
using namespace std;
#include <deque>
int main(){
    deque<int> q;
    q.push_front(10);
    q.push_front(20);
    q.push_front(30);
    q.push_back(40);
    q.push_back(50);
    q.pop_front();
    q.pop_back();
    cout<<q.front()<<endl<<q.back()<<endl;
    cout<<q.size();

}