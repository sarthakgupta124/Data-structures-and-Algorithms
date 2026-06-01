#include <iostream>
using namespace std;
int main(){
    int n=5,low=0,high=n-1,mid,ans;

    int arr[n]={1,5,6,5,4};
    while(low<=high){
        mid=(high+low)/2;
        if(arr[mid]>arr[mid+1]&&arr[mid]>arr[mid-1]){
            ans=mid;
            break;
        }
        else if(arr[mid]>arr[mid+1]&&arr[mid]<arr[mid-1]) high=mid-1;
        else low=mid+1;
    }
}