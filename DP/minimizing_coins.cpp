#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int n,vector<int>&dp,vector<int>coins){//top down bottom
    if(n==0) return 0;
    else if(n==coins[0] || n==coins[2] || n==coins[1]) return 1;
    if(dp[n]==-2){
        int result=INT_MAX;
        for(int i=0;i<coins.size();i++){
            if(n-coins[i]<0) continue;
            if(dp[n-coins[i]]==-2) dp[n-coins[i]]=helper(n-coins[i],dp,coins);
            result=min(dp[n-coins[i]],result);
        }
        if(result==INT_MAX) dp[n]=-1;
        else dp[n]=1+result;
    }
    return dp[n];
}
int helper2(int n,vector<int>&dp,vector<int>coins){//bottom up top
    int i=1;
    while(i<=n){
        if(i==0) dp[i]=0;
        else if(i==coins[0] || i==coins[2] || i==coins[1]) dp[i]=1;
        else dp[i]=1+min(dp[i-coins[0]],min(dp[i-coins[1]],dp[i-coins[2]]));
        i++;
    }
    return dp[n];
}
int main(){
    int n=11;
    vector<int>coins={1,5,7};
    vector<int>dp(n+1,-2);
    cout<<helper2(n,dp,coins);
    return 0;
}