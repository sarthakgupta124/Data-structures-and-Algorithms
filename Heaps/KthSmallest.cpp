#include<iostream>
using namespace std;
#include<queue>
#include <vector>
int main(){
    priority_queue<int>pq;
    vector<int>v;
    v={10,20,-4,6,18,2,105,118};
    int i=0,k=5;
    while(i<v.size()){
        pq.push(v[i]);
        if(pq.size()>k) pq.pop();
        i++;
    }
    cout<<pq.top();
    return 0;
}