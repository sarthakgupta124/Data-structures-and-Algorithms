#include<bits/stdc++.h>
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
bool dfs(int src,int parent,unordered_set<int>&visited){
    visited.insert(src);
    for(auto neighbour:graph[src]){
        if(visited.find(neighbour)!=visited.end() && neighbour!=parent) return true;
        if(visited.find(neighbour)==visited.end()){
            bool res=dfs(neighbour,src,visited);
            if(res) return true;
        }
    }
    return false;
}
bool has_cycle(){
    unordered_set<int>visited;
    bool res=false;
    for(int i=0;i<v;i++){ // this loop will handle the disconnected components also(if we dont use this loop we can detect only the connected component).
        if(visited.find(i)==visited.end()){
            res=dfs(i,-1,visited);
            if(res) return true;
        }
    }
    return false;
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
    bool ans=has_cycle();
    cout<<"cycle detection:"<<ans;
    return 0;
}