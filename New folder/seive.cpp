//to count number of prime number upto certain number
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void change(vector<int>&v,int k,int size){
    for(int j=k+k;j<size;j=j+k) v[j]=0;
}
int main(){
    int x=5000;
    vector<int>v(x+1,1); // 1 means prime number
    for(int i=2;i<=sqrt(x);i++){
        if(v[i]==1){
            change(v,i,x);
        }
    }
    int count=0;
    for(int i=2;i<x;i++) if(v[i]==1) count++;
    cout<<count;


    
}