#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int f(vector<int>&v,int i,int j,vector<vector<int>>&dp){//top down
    if(i==j || i+1==j) return 0;
    int ans=INT_MAX;
    for(int k=i+1;k<=j-1;k++){
        if(dp[i][k]==-1) dp[i][k]=f(v,i,k,dp);
        if(dp[k][j]==-1) dp[k][j]=f(v,k,j,dp);
        ans=min(ans,dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
    }
    dp[i][j]=ans;
    return dp[i][j];
}
int f2(vector<int>&v,int n){//bottom up
    vector<vector<int>>dp(n,vector<int>(n,0));  //if len=1 or 2 cost will zero
    for(int len=3;len<=n;len++){
        for(int i=0;i+len-1<n;i++){ //i=starting point
            int j=i+len-1; //j=ending point
            dp[i][j]=INT_MAX;
            for(int k=i+1;k<=j-1;k++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]+v[i]*v[j]*v[k]);
            }
    
        }
    }
    return dp[0][n-1];
}
int main(){
    int n;
    cout<<"enter value of n:-";
    cin>>n;
    cout<<endl;
    vector<vector<int>>dp(n,vector<int>(n,-1));
    vector<int>v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    cout<<f(v,0,n-1,dp)<<endl;
    cout<<f2(v,n)<<endl;
    return 0;
}