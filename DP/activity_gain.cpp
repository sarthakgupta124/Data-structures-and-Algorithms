#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int n=3; //days
    vector<vector<int>>gain(n,vector<int>(3,-1));//gain with each activity;
    gain={{10,40,70},{20,50,80},{30,60,90}};
    vector<vector<int>>dp(n,vector<int>(3,-1));
    int i=0,j=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            if(i==0) dp[i][j]=gain[i][j];
            else{
                if(j==0){

                    dp[i][j]=gain[i][j]+max(dp[i-1][j+1],dp[i-1][j+2]);
                }
                else if(j==2){

                    dp[i][j]=gain[i][j]+max(dp[i-1][j-1],dp[i-1][j-2]);
                }
                else{
                    dp[i][j]=gain[i][j]+max(dp[i-1][j-1],dp[i-1][j+1]);

                }
            }
        }
    }
    cout<<max(dp[n-1][0],max(dp[n-1][1],dp[n-1][2]));
    return 0;

}