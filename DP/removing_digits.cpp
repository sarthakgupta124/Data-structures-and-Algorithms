#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int n,vector<int>&dp){//top down bottom
    if(n==0) return 0;
    else if(n/10==0) return 1;
    if(dp[n]==-1){
        int temp=n;
        int ans=INT_MAX;
        int a;
        while(temp!=0){
            a=temp%10;
            temp/=10;
            if(a==0) continue;
            if(dp[n-a]==-1) dp[n-a]=helper(n-a,dp);
            ans=min(ans,dp[n-a]);
        }
        dp[n]=ans+1;
    }
    return dp[n];
}
int helper2(int n,vector<int>&dp){//bottom up top
    int i=1;
    while(i<=n){
        if(i==0) dp[i]=0;
        else if(i/10==0) dp[i]=1;

        else{
            int temp=i;
            int ans=INT_MAX;
            int a;
            while(temp!=0){
                a=temp%10;
                temp/=10;
                if(a==0) continue;
                ans=min(ans,dp[i-a]);
            }
            dp[i]=ans+1;
        }
        i++;
    }
    return dp[n];
}
int main(){
    int n=27;
    vector<int>dp(n+1,-1);
    cout<<helper2(n,dp);
    return 0;

}