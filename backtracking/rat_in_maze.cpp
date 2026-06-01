#include<bits/stdc++.h>
using namespace std;
int m,n;
int cnt=0;
vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
vector<vector<int>>visited;
void f(vector<vector<int>>&mat,int i,int j){
    if(i<0||i>=m||j<0||j>=n|| mat[i][j]==1 || visited[i][j]==1) return;
    visited[0][0]=1;
    if(i==m-1 && j==n-1){
        cnt++;
        return;
    }
    visited[i][j]=1;
    for(int d=0;d<4;d++){
        int nr=i+dir[d][0];
        int nc=j+dir[d][1];
        if(nr<0||nr>=m||nc<0||nc>=n) continue;
        f(mat,nr,nc);
    }
    visited[i][j]=0;
}
int main(){
    cin>>m>>n;
    vector<vector<int>>mat(m,vector<int>(n));
    visited.resize(m,vector<int>(n,0));
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cin>>mat[i][j];
        }
    }
    f(mat,0,0);
    cout<<"total count is:"<<cnt;
}