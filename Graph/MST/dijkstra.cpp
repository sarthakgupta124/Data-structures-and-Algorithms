#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<int,int>

vector<list<pp>> graph;
void add_edge(int u,int v,int wt,bool bidir=true){
    graph[u].push_back({v,wt});
    graph[v].push_back({u,wt});
}
unordered_map<int,int> dijkstra(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>>pq; //{wt,node}
    unordered_set<int>visited;
    vector<int>via(n+1);
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++){
        mp[i]=INT_MAX; 
    }
    pq.push({0,src});
    mp[src]=0;
    while(!pq.empty()){
        pp curr=pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        pq.pop();
        for(auto neighbour:graph[curr.second]){
            if(!visited.count(neighbour.first) and mp[neighbour.first]>mp[curr.second]+neighbour.second){
                pq.push({mp[curr.second]+neighbour.second,neighbour.first});
                via[neighbour.first]=curr.second;
                mp[neighbour.first]=mp[curr.second]+neighbour.second;
            }
        }
    }
    return mp;
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n,list<pp> ());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    unordered_map<int,int>sp=dijkstra(src,n);
    int des;
    cin>>des;
    cout<<sp[des]<<endl;
    return 0;
}