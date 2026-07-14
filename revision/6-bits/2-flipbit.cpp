#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(n==0){
        cout<<"1";
    }
    else{
        int k=n;
        int temp;
        while(k>0){
            temp=k;
            k=k&(k-1);
        }
        temp=temp<<1;
        temp=temp-1;
        cout<<(n^temp);
    }
    return 0;
}