#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){

    int n=10,low=0,high=n-1,mid,target;
    vector<int>arr;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        arr.push_back(c);
    }
    cin>>target;
    

    sort(arr.begin(),arr.end());
    bool check=false;
    while(low<=high){
        mid=(low+high)/2;
        if(arr[mid]==target){
            check=true;
            cout<<arr[mid-1];
            break;
        }
        else if(arr[mid]>target) high=mid-1;
        else low=mid+1;
    } 
    if(check==false) cout<<arr[high];
}