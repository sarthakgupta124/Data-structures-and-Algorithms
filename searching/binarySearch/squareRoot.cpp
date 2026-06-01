#include <iostream>
using namespace std;
int main(){
    long long n;
    cin>>n;
    long long low=0,high=n,mid;
    bool f=false;
    while(low<=high){
        mid=(low+high)/2;
        if(mid*mid==n){
            cout<<mid;
            f=true;
            break;

        }
        else if(mid*mid<n) low=mid+1;
        else high=mid-1;
    }
    if(f==false) return low;
}