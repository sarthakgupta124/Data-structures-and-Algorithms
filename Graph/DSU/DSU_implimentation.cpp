#include <iostream>
// #include<vector>
#include <bits/stdc++.h>

using namespace std;
int find(vector<int>&parent,int x){
    //time complexity: log(*n);
    if(parent[x]==x) return x;
    return parent[x]=find(parent,parent[x]); //path compression algorithm.
}
void Union(vector<int>&parent,vector<int>&rank,int a,int b){
    a=find(parent,a);
    b=find(parent,b); 
    if(a==b) return; // trying to merge the componet with the same parent.(forms the cycle)
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
}
int main(){
    int n,m; //n->elements,m->no. of the queries.
    cin>>n>>m;
    vector<int>parent(n+1);
    vector<int>rank(n+1,0);
    for(int i=0;i<=n;i++){
        parent[i]=i;
    }
    while(m--){
        string str;
        cin>>str;
        if(str=="union"){
            int x,y;
            cin>>x>>y;
            Union(parent,rank,x,y);
        }
        else{
            int x;
            cin>>x;
            cout<<find(parent,x)<<endl;
        }
    }
}