#include<bits/stdc++.h>
using namespace std;
vector<list<int>> graph;
int v; //number of vertices
unordered_set<int>visited;
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
bool bfs(int src){
    queue<int>q;
    q.push(src);
    visited.insert(src);
    vector<int>parent(v,-1);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        for(auto neighbour:graph[curr]){
            if(visited.find(neighbour)!=visited.end() && neighbour!=parent[curr]) return true;
            if(visited.find(neighbour)==visited.end()){
                q.push(neighbour);
                visited.insert(neighbour);
                parent[neighbour]=curr;
            }
        }
    }
    return false;
}
bool has_cycle(){
    for(int i=0;i<v;i++){ // this loop will handle the disconnected components also(if we dont use this loop we can detect only the connected component).
        if(visited.find(i)==visited.end()){
            bool res=bfs(i);
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