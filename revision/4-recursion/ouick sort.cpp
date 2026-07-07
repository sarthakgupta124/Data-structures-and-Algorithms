#include <bits/stdc++.h>
using namespace std;
void quick(vector<int>&v,int left,int right){
    if(left>=right) return;
    int pivot=left+(right-left)/2;
    int idx=left;
    for(int i=left;i<=right;i++) if(v[i]<v[pivot]) idx++;
    swap(v[idx],v[pivot]);
    int i=left,j=right;
    while(i<idx && j>idx){
        if(v[j]>=v[idx]) j--;
        else if(v[i]<v[idx]) i++;
        else{
            swap(v[i],v[j]);
            i++;
            j--;
        }
    }
    quick(v,left,idx-1);
    quick(v,idx+1,right);
}
int main(){
    // vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr = {1, 1, 0, 1};
    quick(arr,0,arr.size()-1);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}