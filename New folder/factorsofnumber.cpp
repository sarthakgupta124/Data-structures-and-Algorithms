#include <iostream>
#include <cmath>
using namespace std;
//this print factors in assending order
int main()
{
    int x;
    cin>>x;
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
            cout<<i<<" ";
        }
    }
    for(int i=sqrt(x);i>=1;i--){
        if(x%i==0){
            cout<<x/i<<" ";
        }
    }
}