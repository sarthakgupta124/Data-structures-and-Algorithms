#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
vector<vector<pp>>graph;
int v;
void addedge(int src,int des,int wt){
    graph[src].push_back({wt,des}); //{wt,des}
    graph[des].push_back({wt,src});
}
int dj(int src,int des){
    vector<int>visited(v);
    priority_queue<pp,vector<pp>,greater<pp>>pq;
    // unordered_map<int,int>mp;
    vector<int>distance(v,INT_MAX);
    // for(int i=0;i<v;i++){
    //     mp[i]=INT_MAX;
    // }
    pq.push({0,src});
    distance[src]=0;
    while(!pq.empty()){
        auto curr=pq.top();
        pq.pop();
        if(visited[curr.second]==1) continue;
        visited[curr.second]=1;
        if(curr.second==des) break;
        for(auto ele:graph[curr.second]){
            if(visited[ele.second]==0 && distance[ele.second]>distance[curr.second]+ele.first){
                distance[ele.second]=distance[curr.second]+ele.first;
                pq.push({distance[ele.second],ele.second});
            }
        }
    }
    return distance[des];
}
int main(){
    int e;
    cin>>v>>e;
    graph.resize(v);
    while(e--){
        int a,b,c;
        cin>>a>>b>>c;
        addedge(a,b,c);
    }

}