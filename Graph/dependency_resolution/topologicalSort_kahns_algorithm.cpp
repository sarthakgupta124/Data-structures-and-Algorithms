#include <bits/stdc++.h>
using namespace std;
vector<list<int>>graph;
int v;//vertices
int e;// edges
void add_edge(int a,int b,bool bi_dir=true){
    graph[a].push_back(b);
    if(bi_dir) graph[b].push_back(a);
}
void topological_sort(){ //kahns algorithm;
    vector<int>indegree(v,0);
    for(int i=0;i<v;i++){
        for(auto neighbour:graph[i]){
            indegree[neighbour]++;
        }
    }
    queue<int>q;
    unordered_set<int>vis;
    for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
            vis.insert(i);
        }
    }
    int processed_nodes = 0;
    while(!q.empty()){
        int node=q.front();
        q.pop();
        processed_nodes++;
        cout<<node<<" ";
        for(auto neighbour:graph[node]){
            if(vis.find(neighbour)==vis.end()){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                    vis.insert(neighbour);
                }
            } 
        }
    }
    if (processed_nodes != v) {
        cout << "Error: Graph contains a cycle!" << "\n";
    }
}
int main(){
    cin>>v>>e;
    graph.resize(v,list<int>());

    while(e--){
        int x,y;
        cin>>x>>y;
        add_edge(x,y,false);
    }
    topological_sort();
}