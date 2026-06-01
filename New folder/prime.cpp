#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int x;
    cin>>x;
    bool ans=true;
    if(x==1) ans=false;
    else{
        for(int i=2;i<=sqrt(x);i++){
            if(x%i==0) {
                ans=false;
                break;
            }
        }
    }
    cout<<ans;

}