#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>arr;
    int n;
    cout<<"Enter the size of the array: ";
    cin>>n;
    int s=n;
    while(s-->0){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int i=n-1;
    while(i>0 && arr[i]<=arr[i-1]){
        i--;
    }
    if(i==0){
        reverse(arr.begin(),arr.end());
    }
    else{
        sort(arr.begin()+i,arr.end());
        int j=i;
        while(j<n && arr[j]<=arr[i-1]) j++;
        swap(arr[i-1],arr[j]);
    }
    
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}