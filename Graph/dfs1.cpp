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

void all(int src,int des,vector<int>&visited,vector<int>&pth,vector<vector<int>>&ans){//these are the dfs search
    if(src==des){
        ans.push_back(pth);
        return;
    }
    for(auto ele:graph[src]){
        if(visited[ele]!=1){
            visited[ele]=1;
            pth.push_back(ele);
            all(ele,des,visited,pth,ans);
            pth.pop_back();
            visited[ele]=0;
        }
    }
}
void all_path(){ //dfs
    int s,d;
    cin>>s>>d;
    vector<int>visited(v,0);
    vector<vector<int>>ans;
    vector<int>pth;
    visited[s]=1;
    pth.push_back(s);
    all(s,d,visited,pth,ans);


    cout<<"Paths from"<<s<<" to"<<d<< ":"<<endl;
    if(ans.empty()) {
        cout<<"No path found."<<endl;
    } 
    else {
         for(auto p:ans){
            for(int node:p) {
                cout<<node<<" ";
            }
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
        all_path();
    }

    return 0;
}