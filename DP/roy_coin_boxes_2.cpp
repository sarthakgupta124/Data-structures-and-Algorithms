#include <iostream>
#include <vector>
//important problem //lecture 4 problem 1
using namespace std;
int main(){
    int n=7;
    int m;//number of intervals
    vector<int>f(n+10,0);
    cout<<"enter m:-";
    cin>>m;
    for(int i=0;i<m;i++){
        int left,right;
        cout<<endl<<"left";
        cin>>left;
        cout<<endl<<"right";
        cin>>right;
        f[left]+=1;
        f[right+1]-=1;
    }
    for(int i=1;i<n+10;i++){
        f[i]=f[i]+f[i-1];    //prefix sum
    }
    vector<int>coin_have_box(m+1,0);
    for(int i=1;i<n+1;i++){
        coin_have_box[f[i]]+=1;
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