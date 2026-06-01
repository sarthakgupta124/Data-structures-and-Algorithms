#include <iostream>
#include<vector>
using namespace std;
void storesubset(int arr[],int n,int x,vector<int>v,int k){
    if(x==n){
        if(v.size()==k){
            for(int i=0;i<v.size();i++){
                cout<<v[i];
            }
            cout<<endl;
        }
        return;
    }
    if(v.size()+(n-x)<k) return;
    if(v.size()>k) return;
    storesubset(arr,n,x+1,v,k);
    v.push_back(arr[x]);
    storesubset(arr,n,x+1,v,k);

}
int main(){
    int arr[5]={1,2,3,4,5};
    int n=sizeof(arr)/sizeof(arr[0]);
    vector<int>v;
    int k=3;
    storesubset(arr,n,0,v,k);
    

}


// #include<iostream>
// using namespace std;
// #include <vector>
// #include <algorithm>
// void seq(int n,int k,string op,int i){
    
//     if(k==op.size()){
//         cout<<op<<endl;
//         return;
//     }
//     if(i>n) {
//         return;
//     }
//     seq(n,k,op+to_string(i),i+1);
//     seq(n,k,op,i+1);

// }

// int main(){
//     int n=5,k=3,i=1;
//     seq(n,k,"",i);
//     return 0;
// }