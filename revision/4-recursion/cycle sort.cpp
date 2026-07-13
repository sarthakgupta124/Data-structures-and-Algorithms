#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter number of elemets.";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++) cin>>arr[i];
    int i=0;
    while(i<n){
        if(arr[i]-1==i) i++;
        else{
            swap(arr[i],arr[arr[i]-1]);
        }
    }
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
}