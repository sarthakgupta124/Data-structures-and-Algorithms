#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=6;
    vector<int> v(n,0);
    int arr[6]={21,4,5,78,0,30};
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int in=0;
    for(int i=0;i<n;i++){
        int min=INT16_MAX;
        for(int j=0;j<n;j++){
            if(min>arr[j] && v[j]==0){
                min=arr[j];
                in=j;
            }
        }
        arr[in]=i;
        v[in]=1;

    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}