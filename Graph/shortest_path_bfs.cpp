//shortest distance between the source and the destination

#include <iostream>
#include<vector> 
#include<list>
#include<queue>
using namespace std;
vector<list<int>> graph;
int v; //number of vertices
void add_edge(int src,int des,int bi_dir=true){
    graph[src].push_back(des);
    if(bi_dir) graph[des].push_back(src);
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<":";
        for(auto ele:graph[i]) cout<<ele<<',';
        cout<<endl;
    }
}
void bfs(int src,vector<int>&dist,int v){ //this calculates the all distances between source and the all nodes.
    queue<int>q;
    q.push(src);
    vector<int>visited(v,0);
    visited[src]=1;
    dist[src]=0;
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(visited[neighbour]==0){
                q.push(neighbour);
                visited[neighbour]=1;
                dist[neighbour]=dist[curr]+1;
            }
        }
    }
}
int main(){
    cin>>v;
    graph.resize(v,list<int>());
    int edge;
    cin>>edge;
    while(edge--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    vector<int>dist(v,-1);
    bfs(0,dist,v);
    for(auto ele:dist) cout<<ele<<" ";
    return 0;
}