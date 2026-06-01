//it is stable sort
#include <iostream>
using namespace std;
int main(){
    int arr[6]={-6,5,4,4,2,-1};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
            else break;
        }
        
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}