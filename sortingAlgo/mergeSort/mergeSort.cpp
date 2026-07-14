#include <iostream>
#include <vector>
using namespace std;
void mergeSort(vector<int>&arr,vector<int>&brr,vector<int>&crr){
    int i=0,j=0 ,n=arr.size(),m=brr.size();
    // vector<int> crr(n+m);
    while(i<n||j<m){
        if(arr[i]>brr[j]){
            crr[i+j]=brr[j];
            j++;
        }
        else if(arr[i]<brr[j]){
            crr[i+j]=arr[i];
            i++;
        }
        else{
            crr[i+j]=arr[i];
            i++;
            crr[i+j]=brr[j];
            j++;
        }
        if(i>=n&&j<m){
            crr[i+j]=brr[j];
            j++;
        }
        else if(j>=m&&i<n){
            crr[i+j]=arr[i];
            i++;

        }

    }
    
}
void merge(vector<int>&v){
    int k=v.size();
    if(k==1)  return;
    int n1=k/2,n2=k-n1;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i=0;i<n1;i++) a[i]=v[i];
    for(int j=0;j<n2;j++) b[j]=v[n1+j];

    merge(a);
    merge(b);

    mergeSort(a,b,v);
    //improving space complexity
    a.clear();
    b.clear();


}
int main(){
    int n=6;
    int arr[n]={6,3,0,4,9,8};
    vector<int> v(arr,arr+n);
    merge(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

    

}