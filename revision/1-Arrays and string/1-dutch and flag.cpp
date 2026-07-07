// #include <bits/stdc++.h>
#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int main(){
    vector<int>arr;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    while(n-->0){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int low=0,mid=0,high=arr.size()-1;
    while(mid<=high){
        if(arr[mid]==1) mid++;
        else if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            low++;
            mid++;
        }
        else{
            swap(arr[mid],arr[high]);
            high--;
        }
    }
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
    // return 0;
}