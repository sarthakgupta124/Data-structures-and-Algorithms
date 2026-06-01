#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>dir={{-2,-1},{-2,1},{-1,-2},{-1,2},{1,-2},{1,2},{2,-1},{2,1}};
bool isSafe(vector<vector<int>>&grid,int i,int j,int n){
    return i>=0 && i<n && j>=0 && j<n && grid[i][j]==-1;
}
void display(vector<vector<int>>&grid,int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}
void f(vector<vector<int>>&grid,int i,int j,int n,int count){
    if(count==n*n-1){
        //last position
        grid[i][j]=count;
        display(grid,n);
        cout<<"*****"<<endl;
        grid[i][j]=-1;
        return;
    }
    for(int k=0;k<8;k++){
        int nr=i+dir[k][0];
        int nc=j+dir[k][1];
        if(isSafe(grid,nr,nc,n)){
            grid[i][j]=count;
            f(grid,nr,nc,n,count+1);
            grid[i][j]=-1;
        }
    }
    
}
void knightstour(int i,int j,int n){
    //can we tour the whole board?
    vector<vector<int>>grid(n,vector<int>(n,-1)); //-1 denotes the vacant place
    f(grid,i,j,n,0);
}
int main(){
    knightstour(0,0,5);
    return 0;
}