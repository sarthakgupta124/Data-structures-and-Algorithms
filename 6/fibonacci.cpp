#include <iostream>
using namespace std;
int main(){
    cout<<"enter value of n:";
    int x;
    cin>>x;
    int a=1,b=1;
    // cout<<a<<endl<<b<<endl;
    int c=1;
    while(x>2){
        c=a+b;
        a=b;
        b=c;
        // cout<<c<<endl;
        x-=1;
    }
    cout<<c;
    return 0;


}