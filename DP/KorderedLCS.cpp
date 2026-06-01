#include <iostream>
using namespace std;//lecture 4,  3.50hr
long long dp[2005][2005][8];
long long korderLCS(int *a,int *b,int n,int m,int i,int j,int k){
    if(n==i || m==j) return 0;
    if(dp[i][j][k]!=-1) return dp[i][j][k];
    long long res=0;
    if(a[i]==b[j]){
        res=1+korderLCS(a,b,n,m,i+1,j+1,k);   //LCA=least common substring

    }
    else{
        if(k>0){
            res=1+korderLCS(a,b,n,m,i+1,j+1,k-1);
        }
        res=max(res,korderLCS(a,b,n,m,i+1,j,k));
        res=max(res,korderLCS(a,b,n,m,i,j+1,k));
    }
    return dp[i][j][k]=res;
}

int main(){

}