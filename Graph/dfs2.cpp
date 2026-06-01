#include <iostream>
#include<vector> 
#include<list>
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

void all2(int src,int des,vector<int>&pth,vector<vector<int>>&ans,vector<int>&visited){//these are the dfs search
    if(src==des){
        pth.push_back(src);
        ans.push_back(pth);
        pth.pop_back();
        return ;
    }
    visited[src]=1;
    pth.push_back(src);
    for(auto nieghbour:graph[src]){
        if(visited[nieghbour]!=1){
            all2(nieghbour,des,pth,ans,visited);
        }
    }
    pth.pop_back();
    visited[src]=0;
    return;
    
}
void all_path2(int src,int des){ ///dfs
    vector<int>visited(v,0);
    vector<vector<int>>ans;
    vector<int>pth;
    all2(src,des,pth,ans,visited);

    cout<<"Paths from "<<src<<" to "<<des<< " (Using all2):"<<endl;
    if(ans.empty()) {
        cout<<"No path found."<<endl;
    } else {
         for(auto p:ans){
            for(int node:p) cout<<node<<" ";
            cout<<endl;
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
    int n;
    cout<<"searching the all path.";
    cin>>n;
    while(n-->0){
        int s,des;
        cin>>s>>des;
        all_path2(s,des);
    }
    return 0;
}