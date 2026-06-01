#include <iostream>
#include <vector>
//important problem //lecture 4 problem 1
using namespace std;
int main(){
    int n=7;
    int m;//number of intervals
    vector<int>dp(n+1,-1);
    vector<int>l(n+1,0);
    vector<int>r(n+1,0);
    cout<<"enter m:-";
    cin>>m;
    for(int i=0;i<m;i++){
        int left,right;
        cout<<endl<<"left";
        cin>>left;
        cout<<endl<<"right";
        cin>>right;
        l[left]+=1;
        r[right]+=1;
    }
    for(int i=1;i<=n;i++){
        if(i==1) dp[i]=l[i];
        else{
            dp[i]=l[i]+dp[i-1]-r[i-1];
        }
    }
    //now dp contains how many coins are there in the each boxes;
    //mow create vector that (i=1)-> how may boxes have 1 coin
    vector<int>coin_have_box(m+1,0);
    for(int i=1;i<n+1;i++){
        coin_have_box[dp[i]]+=1;
    }
    cout<<"c3";
    //now create the suffix sum to get atleast ans
    vector<int>sufix_sum(m+1,0);
    for(int i=m;i>0;i--){
        if(i==m) sufix_sum[m]=coin_have_box[m];
        else sufix_sum[i]=coin_have_box[i]+sufix_sum[i+1];
    }
    cout<<"c4";
    cout<<endl;
    int q;
    cin>>q;
    for(int i=0;i<q;i++){
        cout<<"enter coins to find boxes which have atleast that coin:-";
        int k;
        cin>>k;
        if(k>m) cout<<0<<endl;
        else cout<<sufix_sum[k]<<endl;
    }
}