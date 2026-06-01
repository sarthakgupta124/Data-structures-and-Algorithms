//it is unstable sort
#include <iostream>
using namespace std;
int main(){
    int arr[6]={6,5,4,3,2,1};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<n-1;i++){
        int min=arr[i],ind=i;
        for(int j=i;j<n;j++){
            if(arr[j]<min){
                min=arr[j];
                ind=j;
            }
        }
        swap(arr[ind],arr[i]);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}