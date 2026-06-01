#include <iostream>
#include <string>
using namespace std;
void gcd(int a,int b,int mn){
    if(mn<2){
        cout<<1;
        return;
    }
    if(a%mn==0&&b%mn==0){
        cout<<mn;
        return;
    }
    else{
        gcd(a,b,mn-1);
    }
    

}
int main(){
    int a,b;
    cin>>a>>b;
    if(a%min(a,b)==0&&b%min(a,b)==0) cout<<min(a,b);
    else{
        gcd(a,b,min(a,b)/2);
    }

    

}