#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void permutation(vector<int>&ar,vector<vector<int>>&v){
    int node=-1;
    for(int i=ar.size()-1;i>0;i--){
        if(ar[i]>ar[i-1]){
            node=i-1;
            break;
        }
    }
    if(node==-1) return;

    sort(ar.begin()+node+1,ar.end());
    for(int i=node+1;i<ar.size();i++){
        if(ar[node]<ar[i]){
            swap(ar[node],ar[i]);
            break;
        }
    }
    v.push_back(ar);
    permutation(ar,v);


}
int main(){
    int n=4;
    vector<int> arr;
    arr={1,1,2};

    vector<vector<int>> v;
    v.push_back(arr);
    permutation(arr,v);
    for(int i=0;i<v.size();i++){
        for(int j=0;j<3;j++){
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
}