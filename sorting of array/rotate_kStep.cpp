#include<iostream>
using namespace std;
int main(){
    int f;
    cin>>f;
    int arr[f];
    for(int i=0;i<f;i++){
        cin>>arr[i];
    }
    int k;
    cin>>k;
    if(k>=f){
        k=k%f;
    }
    int brr[f];
    for(int i=0;i<f;i++){
        if(k+i>=f){

            brr[i+k-f]=arr[i];
        }
        else brr[i+k]=arr[i];
    }
    for(int i=0;i<f;i++){
        cout<<brr[i];
    }
}