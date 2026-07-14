#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    int k=n^m;
    int ans=0;
    while(k>0){
        if(k&1) ans++;
        k=k>>1;
    }
    cout<<ans;
    return 0;
}