#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& a,vector<int>& b,vector<int>& arr) {
    int m=a.size(),n=b.size(),i=0,j=0;
    while(i<m && j<n){
        if(a[i]>b[j]){
            arr[i+j]=b[j];
            j++;
        }
        else if(a[i]<b[j]){
            arr[i+j]=a[i];
            i++;
        }
        else{
            arr[i+j]=a[i];
            i++;
            arr[i+j]=b[j];
            j++;
        }
    }
    while(i<m) arr[i+j]=a[i++];
    while(j<n) arr[i+j]=b[j++];
}
void mergeSort(vector<int>& arr) {
    int k=arr.size();
    if(k==1) return;
    int mid = k/2;
    int n1=mid,n2=k-mid;
    vector<int>a(n1);
    vector<int>b(n2);
    for(int i=0;i<n1;i++) a[i]=arr[i];
    for(int i=0;i<n2;i++) b[i]=arr[i+n1];
    mergeSort(a);
    mergeSort(b);
    merge(a,b,arr);
}
int main(){
    // vector<int> arr = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr = {1, 1, 0, 1};
    mergeSort(arr);
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}