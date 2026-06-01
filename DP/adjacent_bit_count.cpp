#include <iostream>
#include <cstring>
using namespace std;
int dp[105][105][2];
int f(int n,int k,int last){
    if(n==0) return 0;
    if(n==1){
        if(k==0) return 1;
        else return 0;
    }
    if(dp[n][k][last]!=-1) return dp[n][k][last];
    if(last==0){
        dp[n][k][last]=(f(n-1,k,0)+f(n-1,k,1));
    }
    else{
        dp[n][k][last]=(f(n-1,k,0)+f(n-1,k-1,1));
    }
    return dp[n][k][last];
}
int main(){
    memset(dp,-1,sizeof dp);
    cout<<f(5,2,0)+f(5,2,1);

}