#include <iostream>
#include<vector> 
#include<unordered_map>
using namespace std;
vector<unordered_map<int,int>> graph;
int v; //number of vertices
void add_edge(int src,int des,int wieght,int bi_dir=true){
    graph[src].insert({des,wieght});
    if(bi_dir) graph[des].insert({src,wieght});
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<":";
        for(auto ele:graph[i]) cout<<"("<<ele.first<<','<<ele.second<<")";
        cout<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v,unordered_map<int,int>());
    int edge;
    cin>>edge;
    while(edge--){
        int s,d,w;
        cin>>s>>d>>w;
        add_edge(s,d,w);
    }
    display();
    return 0;
}