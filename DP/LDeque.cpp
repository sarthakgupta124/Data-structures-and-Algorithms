#include <iostream>
#include <vector>
#include <climits>
using namespace std; //lecture 4:3.21hr
int f(vector<int>&v,int i,int j,vector<vector<int>>&dp){//top down
    if(i==j) return v[i];
    if(dp[i][j]!=-1) return dp[i][j];
    dp[i][j]=max(v[i]-f(v,i+1,j,dp),v[i]-f(v,i,j-1,dp));
    return dp[i][j];
}
int main(){
    int n;
    cout<<"enter value of n:-";
    cin>>n;
    cout<<endl;
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<f(v,0,n-1,dp);
    return 0;
}