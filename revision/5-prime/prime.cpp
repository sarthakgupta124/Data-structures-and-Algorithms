#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number:";
    cin>>n;
    int k=sqrt(n);
    bool p=false;
    for(int i=2;i<k;i++){
        if(n%k==0){
            p=true;
            break;
        }
    }
    if(p) cout<<"NA";
    else cout<<"Prime";
    return 0;
}