
#include <bits/stdc++.h>

using namespace std;
int find(vector<int>&parent,int x){
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]);
}
bool Union(vector<int>&parent,vector<int>&rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b); 
    if(a==b) return true;
    if(rank[a]>=rank[b]){
        rank[a]++; 
        parent[b]=a;
    }
    else{
        rank[b]++;
        parent[a]=b;
    }
    return false;
}
int main(){
    int n,m; //n->verties,m->no. of edges.
    cin>>n>>m;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    bool ch;
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            ch=Union(parent,rank,x,y);
            if(ch){
                cout<<"there is cycle in the graph.";
                break;
            }
        }
    }
    if(!ch) cout<<"No cycle detected";
}