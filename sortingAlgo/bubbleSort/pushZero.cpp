// push zero to eend and maintain the relative order
#include <iostream>
using namespace std;
int main(){
    int arr[6]={6,0,3,3,0,5};
    int n=6;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int pss=0;
    for(int i=0;i<n-1;i++){
        bool a=true;
        for(int j=0;j<n-1-i;j++){
            if(arr[j]<arr[j+1] && arr[j]==0){    //if condition is arr[j]==0 then it is unstable sort and if cond is arr[j]<arr[j+1] && arr[j]==0 it is stable sort.
                swap(arr[j],arr[j+1]);
                a=false;
            }
        }
        pss++;
        if(a==true) break;
    }
    cout<<pss<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}