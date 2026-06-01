#include <iostream>
#include<vector> 
#include<unordered_set>
using namespace std;
vector<unordered_set<int>> graph;
int v; //number of vertices
void add_edge(int src,int des,int bi_dir=true){
    graph[src].insert(des);
    if(bi_dir) graph[des].insert(src);
}
void display(){
    for(int i=0;i<graph.size();i++){
        cout<<i<<":";
        for(auto ele:graph[i]) cout<<ele<<" ";
        cout<<endl;
    }
}
int main(){
    cin>>v;
    graph.resize(v,unordered_set<int>());
    int edge;
    cin>>edge;
    while(edge--){
        int s,d;
        cin>>s>>d;
        add_edge(s,d);
    }
    display();
    return 0;
}