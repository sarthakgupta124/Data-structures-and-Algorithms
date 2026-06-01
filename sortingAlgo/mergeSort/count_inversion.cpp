//brute force solution
#include <iostream>
using namespace std;
int main(){
    int n=5;
    int arr[n]={5,1,8,2,3};
    int count_in=0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]) count_in++;
        }
    }
    cout<<count_in;
}