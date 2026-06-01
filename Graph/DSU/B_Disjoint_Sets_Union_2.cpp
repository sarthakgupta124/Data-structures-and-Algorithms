//codeforces
#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int>sz;
vector<int>minimal;
vector<int>maximum;
int get(vector<int>&parent,int x){
    if(parent[x]==x) return x;
    return parent[x] =get(parent,parent[x]);
}
void Union(vector<int>&parent,vector<int>&rank,int a,int b){
    a=get(parent,a);
    b=get(parent,b);
    if(a==b) return;
    if(rank[a]>=rank[b]){
        parent[b]=a;
        rank[a]++;
        sz[a]+=sz[b];
        minimal[a]=min(minimal[a],minimal[b]);
        maximum[a]=max(maximum[a],maximum[b]);
    }
    else{
        parent[a]=b;
        rank[b]++;
        sz[b]+=sz[a];
        minimal[b]=min(minimal[a],minimal[b]);
        maximum[b]=max(maximum[a],maximum[b]);
    }
}
int main(){
    int m,n;
    cin>>m>>n;
    sz.resize(m+1);
    minimal.resize(m+1);
    maximum.resize(m+1);
    vector<int>parent(m+1);
    vector<int>rank(m+1);
    for(int i=0;i<=m;i++){
        parent[i]=minimal[i]=maximum[i]=i;
        sz[i]=1;
        rank[i]=0;
    }
    while(n--){
        string str;
        cin>>str;
        if(str=="union"){
            int a,b;
            cin>>a>>b;
            Union(parent,rank,a,b);
            // cout<<minimal[p]<<" "<<maximum[p]<<" "<<size[p]<<endl;
        }
        else{
            int x;
            cin>>x;
            int p=get(parent,x);
            cout<<minimal[p]<<" "<<maximum[p]<<" "<<sz[p]<<endl;
        }
    }
}