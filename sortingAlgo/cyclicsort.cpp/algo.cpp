//only for continuos element starting from 1
#include<iostream>
#include<vector>
using namespace std;

int main(){
    int n=5;
    vector<int>v(n);
    v={4,3,2,5,1};
    int i=0;
    while(i<n){
        int cortinx=v[i]-1;
        if(i==cortinx) i++;
        else{
            swap(v[i],v[cortinx]);
        }
    }
    
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}