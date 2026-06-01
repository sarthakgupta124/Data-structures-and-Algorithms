// let x>y so (x&y)<y always true
//we get maximum length subarray when elem is maximum;
#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> arr={1,4,5,13,3,6,7,13};
    int i=0,j=1,length=1, ans=1;
    while(j<arr.size()){
        if(arr[i]==arr[j]) length++;
        else{
            i=j;
            length=1;
        }
        if(arr[j]>arr[i]){
            i=j;
            
            length=1;
        }
        ans=max(ans,length);
        j++;
    }
    cout<<ans;
}