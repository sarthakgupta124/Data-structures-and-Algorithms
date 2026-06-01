#include <iostream>
#include<vector> 
#include<list>
#include<unordered_set>
using namespace std;
vector<list<int>> graph;
int v; //number of vertices
void add_edge(int src,int des,int bi_dir=true){
    graph[src].push_back(des);
    if(bi_dir) graph[des].push_back(src);
}
void dfs(int node,unordered_set<int>&visited){
    visited.insert(node);
    for(auto neighbour:graph[node]){
        if(visited.find(neighbour)==visited.end()){
            dfs(neighbour,visited);
        }
    }
}
int connected_component(){
    int result=0;
    unordered_set<int>visited;
    for(int i=0;i<v;i++){
        //dfs on the every nodes.
        if(visited.find(i)==visited.end()){
            result++;
            dfs(i,visited);
        }
    }
    return result;
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

    return 0;
}