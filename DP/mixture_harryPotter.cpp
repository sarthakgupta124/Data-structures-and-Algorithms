#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int f(vector<int>&v,int i,int j,vector<vector<int>>&dp){//top down
    if(i==j) return 0;
    if(i+1==j) return v[i]*v[j];
    if(dp[i][j]!=-1) return dp[i][j];
    int ans=INT_MAX;
    for(int k=i+1;k<=j-1;k++){
        if(dp[i][k]==-1) dp[i][k]=f(v,i,k,dp);
        if(dp[k+1][j]==-1) dp[k+1][j]=f(v,k+1,j,dp);
        int res1=0,res2=0;
        for(int m=i;m<=k;m++) res1=(res1%100+v[m])%100;
        for(int m=k+1;m<=j;m++) res2=(res2%100+v[m])%100;
        ans=min(ans,dp[i][k]+dp[k+1][j]+res1*res2);
    }
    dp[i][j]=ans; 
    return dp[i][j];
}
int f2(vector<int>&v,int n){//bottom up
    vector<vector<int>>dp(n,vector<int>(n,0));  //if len=1 cost will zero
    for(int len=2;len<=n;len++){
        for(int i=0;i+len-1<n;i++){ //i=starting point
            int j=i+len-1; //j=ending point
            if(i+1==j){
                dp[i][j]=v[i]*v[j];
            }
            else{
                dp[i][j]=INT_MAX;
                for(int k=i+1;k<=j-1;k++){
                    int res1=0,res2=0;
                    for(int m=i;m<=k;m++) res1=(res1%100+v[m])%100;
                    for(int m=k+1;m<=j;m++) res2=(res2%100+v[m])%100;
                    dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+res1*res2);
                }
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
}