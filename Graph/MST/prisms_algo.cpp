//this code is the one based indexing.

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define pp pair<int,int>

vector<list<pp>> graph;
void add_edge(int u,int v,int wt,bool bidir=true){
    graph[u].push_back({v,wt});
    graph[v].push_back({u,wt});
}
ll prims(int src,int n){
    priority_queue<pp,vector<pp>,greater<pp>>pq; //{wt,node}
    unordered_set<int>visited;
    vector<int>parent(n+1);
    unordered_map<int,int>mp;
    for(int i=1;i<=n;i++){
        mp[i]=INT_MAX;
    }
    pq.push({0,src});
    mp[src]=0;
    int total_count=0; //n-1 edges
    int res=0; //sum of wt
    while(total_count<n && !pq.empty()){
        pp curr=pq.top();
        if(visited.count(curr.second)){
            pq.pop();
            continue;
        }
        visited.insert(curr.second);
        total_count++;
        res+=curr.first;
        pq.pop();
        for(auto neighbour:graph[curr.second]){
            if(!visited.count(neighbour.first) and mp[neighbour.first]>neighbour.second){
                pq.push({neighbour.second,neighbour.first});
                parent[neighbour.first]=curr.second;
                mp[neighbour.first]=neighbour.second;
            }
        }
    }
    return res;
}
int main(){
    int n,m;
    cin>>n>>m;
    graph.resize(n+1,list<pp> ());
    while(m--){
        int u,v,wt;
        cin>>u>>v>>wt;
        add_edge(u,v,wt);
    }
    int src;
    cin>>src;
    cout<<prims(src,n)<<endl;
    return 0;
}