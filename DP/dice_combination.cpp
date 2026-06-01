#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int helper(int n,vector<int>&dp){//top down bottom
    if(n==0) return 1;
    int sum=0;
    if(dp[n]==-1){
        for(int i=1;i<=6;i++){
            if(n-i<0) break;
            else{
                sum+=helper(n-i,dp);
            }
        }
        dp[n]=sum;
    }
    return dp[n];
}
int helper2(int n,vector<int>&dp){//bottom up top
    int i=0;
    while(i<=n){
        if(i==0 || i==1) dp[i]=1;
        else {
            int sum=0;
            for(int j=1;j<=6;j++){
                if(i-j<0) break;
                else sum+=dp[i-j];
            }
            dp[i]=sum;
        }
        i++;
    }
    return dp[n];
}
int main(){
    int n=10;
    vector<int>dp(n+1,-1);
    cout<<helper(n,dp)<<endl;
    cout<<helper2(n,dp);
    return 0;

}