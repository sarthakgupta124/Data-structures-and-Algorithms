#include<iostream>
using namespace std;
int main(){
    int i=0,j=0 ,n=5,m=8;
    int arr[n]={1,2,3,4,5},brr[m]={2,2,4,6,8,9,17,32},crr[n+m];
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
        if(j>=m&&i<n){
            crr[i+j]=arr[i];
            i++;

        }
        
    }
    for(int i=0;i<n+m;i++) cout<<crr[i]<<" "; 
}