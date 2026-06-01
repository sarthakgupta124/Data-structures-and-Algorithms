#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        int sum=0;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            sum+=a;
        }
        if((sum%2!=0)) cout<<"yes"<<endl;
        else if((n*k)%2==0) cout<<"yes"<<endl;
        else cout<<"no"<<endl;
    }
    return 0;
}