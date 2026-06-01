#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n=5,low=0,high=n-1,mid,ans,ans2;

    vector<int> arr;
    arr={2,3,4,0,1};
    int target1=arr[0],target=4;
    sort(arr.begin(),arr.end());

    while(low<=high){
        mid=(high+low)/2;
        if(arr[mid]==target){
            ans=mid;
            break;
        }
        else if(arr[mid]>target) high=mid-1;
        else low=mid+1;
    }
    low=0,high=n-1;
    while(low<=high){
        mid=(high+low)/2;
        if(arr[mid]==target1){
            ans2=mid;
            break;
        }
        else if(arr[mid]>target1) high=mid-1;
        else low=mid+1;
    }
    cout<<ans-ans2;
}