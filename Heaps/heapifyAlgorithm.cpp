#include <iostream>
#include <climits>
using namespace std;
int main(){
    int arr[]={INT_MIN,10,2,14,11,1,4};
    int n=sizeof(arr)/sizeof(arr[0])-1;
    int i=n/2;
    while(i>=1){
        int l=2*i;
        int r=2*i+1;
        if(l>n && r>n) i--;
        else if(l<=n && r>n){
            if(arr[i]>arr[l]){
                swap(arr[i],arr[l]);
                i=l;
            }
            else i--;
        }
        else if(arr[i]>arr[l] || arr[i]>arr[r]){
            if(arr[l]>arr[r]){
                swap(arr[i],arr[r]);
                i=r;
            }
            else{
                swap(arr[i],arr[l]);
                i=l;
            }
        }
        else i--;
    }
    for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
}