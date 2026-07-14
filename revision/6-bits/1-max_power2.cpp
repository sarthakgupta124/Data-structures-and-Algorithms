#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int x=0;
    while((1<<(x+1)) <= n) x++;
    cout<<(1<<x)<<endl;
    cout<<"method 2"<<endl;
    int k=n;
    int temp;
    while(k>0){
        temp=k;
        k=k&(k-1);
    }
    cout<<temp<<endl;
    cout<<"method 3"<<endl;
    n=n>>1 | n;
    n=n>>2 | n;
    n=n>>4 | n;
    n=n>>8 | n;
    n=n>>16 | n;
    cout<<((n+1)>>1);
    return 0;
}