#include <iostream>
#include <cstring>
#include <vector>
using namespace std; // lecture 5 : 1.14 hrs
// int dp[105][105];
int f(int n,vector<int>c,vector<int>a,int i,int x){ // no. assistant - no. captain
    if(i==n) return 0;
    int res;
    if(x==0){
        res=a[i]+f(n,c,a,i+1,x+1);
    }
    else if(x==n-i){
        res=c[i]+f(n,c,a,i+1,x-1);
    }
    else{
        res=min(c[i]+f(n,c,a,i+1,x-1),a[i]+f(n,c,a,i+1,x+1));
    }
    return res;
}
int main(){
    // memset(dp,-1,sizeof dp);
    vector<int>c;
    c={5,6,8,9};
    vector<int>a;
    a={3,2,1,6};
    cout<<a[0]+f(4,c,a,1,1);

}