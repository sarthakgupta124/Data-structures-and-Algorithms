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
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(v[j]<v[j-1]) swap(v[j],v[j-1]);
            else break;
        }
    }
    cout<<"The sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
}