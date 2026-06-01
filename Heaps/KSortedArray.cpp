#include<iostream>
using namespace std;
#include<queue>
#include <vector>
int main(){
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int>v;
    v={6,5,3,2,8,10,9};
    int i=0,k=3,j=0;
    while(i<v.size()){
        pq.push(v[i]);
        if(pq.size()>k){
            v[j]=pq.top();
            j++;
            pq.pop();
        }
        i++;
    }
    while(!pq.empty()){
        v[j]=pq.top();
        j++;
        pq.pop();
    }
    for(int ele:v) cout<<ele<<" ";
    return 0;
}