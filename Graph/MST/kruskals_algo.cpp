#include <bits/stdc++.h>
using namespace std;
int find(vector<int>&parent,int val){
    if(val==parent[val]) return val;
    return parent[val]=find(parent,parent[val]);
}
bool Union(vector<int>&parent,vector<int>&rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b);
    if(a==b) return false;
    if(rank[a]>rank[b]){
         
        parent[b]=a;
    }
    else if(rank[b]>rank[a]){
        parent[a]=b;
    }
    else{
        parent[b]=a;
        rank[a]++;
    }
    return true;
}
struct Edge{
    int src;
    int des;
    int wt;
};
bool cmp(Edge e1,Edge e2){
    return e1.wt<e2.wt;
}
long long int kruskals(vector<Edge>&inputs,int n, int e){
    sort(inputs.begin(),inputs.end(),cmp);
    vector<int>parent(n+1);
    for(int i=0;i<n;i++) parent[i]=i;
    vector<int>rank(n+1,1);
    int edgecount=0; // for tree of n vertices there should be the n-1 edges//maximum
    int i=0;
    long long int minwt=0;
    while(edgecount<n-1 and i<inputs.size()){
        Edge curr=inputs[i];
        bool ch=Union(parent,rank,curr.src,curr.des);
        if(ch){
            minwt+=curr.wt;
            edgecount++;
        }
        i++;
    }
    return minwt;

}
int main(){
    int n,e;
    cin>>n>>e;
    vector<Edge>v(e);
    for(int i=0;i<e;i++){
        cin>>v[i].src>>v[i].des>>v[i].wt;
    }
    cout<<kruskals(v,n,e);
    return 0;
}