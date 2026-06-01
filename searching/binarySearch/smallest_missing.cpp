#include <iostream>
using namespace std;
int main(){
    int n=8,low=0,high=n-1,arr[n]={0,1,2,3,4,5,6,8},mid,ans;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==mid){
            low=mid+1;

        }
        else{
            ans=mid;
            high=mid-1;
        }

    }
    cout<<ans;
}