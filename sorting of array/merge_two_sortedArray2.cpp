// merge_two_sortedArray without third shorted array size of arr is n+m and brr is m
#include<iostream>
using namespace std;
int main(){
    int  n=5,m=8 ,k=n+m-1,i=n-1,j=m-1;
    int arr[n+m]={1,2,3,4,5,0,0,0,0,0,0,0,0},brr[m]={2,2,4,6,8,9,17,32};
    while(i>=0 && j>=0&&k>=0){
        if(arr[i]>brr[j]){
            arr[k]=arr[i];
            k--;
            i--;
        }
        else if(arr[i]<brr[j]){
            arr[k]=brr[j];
            k--;
            j--;
        }
        else{
            arr[k]=arr[i];
            k--;
            i--;
            arr[k]=brr[j];
            k--;
            j--;

        }
        if(i<0&&j>=0){
            arr[k]=brr[j];
            k--;
            j--;
        }
        if(j<0&&i>=0){
            arr[k]=arr[i];
            k--;
            i--;

        }
        
    }
    for(int i=0;i<n+m;i++) cout<<arr[i]<<" "; 
}