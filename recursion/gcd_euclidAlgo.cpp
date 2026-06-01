#include <iostream>
#include <string>
using namespace std;
void gcd(int divident,int divisor){
    int rem=divident%divisor;
    if(rem==0) {
        cout<<divisor<<endl;
        return;
    }
    else{
        gcd(divisor,rem);

    }
    

}
int main(){
    int a,b;
    cin>>a>>b;
    gcd(max(a,b),min(a,b));

    

}