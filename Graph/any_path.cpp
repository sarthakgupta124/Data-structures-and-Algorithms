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
bool any(int src,int des,vector<int>&visited){
    visited[src]=1;
    if(src==des) return true;
    for(auto ele:graph[src]){
        if(visited[ele]!=1){
            if(any(ele,des,visited)) return true;
        }
    }
    return false;
}
void any_path(){
    int s,d;
    cin>>s>>d;
    vector<int>visited(v,0);
    cout<<any(s,d,visited)<<endl;
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
    cout<<"searching the any path.";
    int n;
    cin>>n;
    while(n-->0){
        any_path();
    }
    return 0;
}