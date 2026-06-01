#include <iostream>
#include<vector>
using namespace std;
void storesubset(int arr[],int n,int x,vector<int>v){
    if(x==n){
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return;
    }
    
    if(v.size()==0 ||arr[x-1]==v[v.size()-1]){
        storesubset(arr,n,x+1,v);
        v.push_back(arr[x]);
        storesubset(arr,n,x+1,v);
    }
    
    else{
        
        for(int i=0;i<v.size();i++){
            cout<<v[i];
        }
        cout<<endl;
        return;
    }

}
int main(){
    int arr[4]={1,2,3,4};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    storesubset(arr,n,0,v);
    

}