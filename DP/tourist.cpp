//lecture 6,first question
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
int dp[101][101][101];
int tb(vector<vector<char>>&grid,int w,int h,int i,int j,int x,int y){
    if(w<i || h<j ||w<x || h<y || grid[i][j]=='#' || grid[x][y]=='#') return 0;
    if(w==i && h==j) return grid[i][j]=='*';
    if(dp[i][j][x]!=-1) return dp[i][j][x];
    int val=max(max(tb(grid,w,h,i+1,j,x+1,y),tb(grid,w,h,i,j+1,x+1,y)),max(tb(grid,w,h,i+1,j,x,y+1),tb(grid,w,h,i,j+1,x,y+1)));
    if(grid[i][j]=='*') val+= 1;
    if(grid[x][y]=='*') val+= 1;
    if(grid[x][y]=='*' && x==i && y==j) val-= 1;
    return dp[i][j][x]=val;
}
    
int main(){ 
    memset(dp,-1,sizeof dp);
    int w,h;
    cin>>w;
    cin>>h;
    vector<vector<char>>grid(w,vector<char>(h,'0'));
    for(int k=0;k<w;k++){
        for(int m=0;m<h;m++){
            cin>>grid[k][m];
        }
    }
    cout<<tb(grid,w-1,h-1,0,0,0,0);
}