#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int n,vector<int>&dp){//top down bottom
    if(n==1) return 0;
    else if(n==2) return 1;
    else if(n==3) return 1;
    if(dp[n]==-1){
        int a=INT_MAX,b=INT_MAX,c=INT_MAX;
        a=helper(n-1,dp);
        if(n%2==0) b=helper(n/2,dp);
        if(n%3==0) c=helper(n/3,dp);
        dp[n]=1+min(a,min(b,c));
    }
    return dp[n];
}
int helper2(int n,vector<int>&dp){//bottom up top
    int i=1;
    while(i<=n){
        if(n==1) return 0;
        else if(i==2 || i==3) dp[i]=1;
        else dp[i]=1+min(dp[i-1],min((i%2==0)?dp[i/2]:INT_MAX,(i%3==0)?dp[i/3]:INT_MAX));
        i++;
    }
    return dp[n];
}
int main(){
    int n=100;
    vector<int>dp(n+1,-1);
    cout<<helper2(n,dp);
    return 0;

}