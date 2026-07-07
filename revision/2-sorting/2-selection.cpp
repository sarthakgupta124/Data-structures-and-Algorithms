#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int>v;
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    cout<<"Enter the elements: ";
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    for(int i=0;i<n-1;i++){
        int min_index=i;
        for(int j=i;j<n;j++){
            if(v[j]<v[min_index]){
                min_index=j;
            }
        }
        swap(v[i],v[min_index]);
    }
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}