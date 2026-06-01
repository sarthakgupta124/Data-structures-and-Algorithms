//down and right steps are allowed only.(0,0) se (n,m) jana hai
//n,m like matrix of n cross m.
#include <iostream>
#include<string>
using namespace std;
int path(int n,int m){
    if(n==1&&m==1) return 0;
    if(n==1) return 1;
    if(m==1) return 1;
    return (path(n-1,m)+path(n,m-1));
}
void printpath(int n,int m,string s){
    
    if(n<1) return;
    if(m<1) return;
    if(n==1 && m==1){
        cout<<s<<endl;
        return;
    }
    printpath(n,m-1,s+"R");
    printpath(n-1,m,s+"D");
}
int main(){
    int a,b;
    cin>>a>>b;
    // cout<<"number of paths:"<<path(a,b);
    printpath(a,b,"");
}