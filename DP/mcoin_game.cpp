#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    int k=2,l=3,m=5; //m->number of games
    vector<int>dp(1000000,-1);
    int i=1;
    while(i<=1000000){
        if(i==1 || i==k || i==l) dp[i]=1; //1->winning stage
        else {
            bool ans=true;
            if(i-1>=1) ans*=dp[i-1];
            if(i-k>=1) ans*=dp[i-k];
            if(i-l>=1) ans*=dp[i-l];
            dp[i]=!ans;
        }
        i++;
    }
    for(int i=0;i<m;i++){ 
        cout<<"enter number of coins:-";
        int s;
        cin>>s;
        if(dp[s]==1){ //winning state
            cout<<"A"<<endl; //since game is started always with A
        }
        else cout<<"B"<<endl;
    }
    return 0;

}