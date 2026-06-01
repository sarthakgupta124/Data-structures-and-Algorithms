#include <iostream>
#include<vector>
#include<climits>
using namespace std;
int kthlargest(vector<int>&v,int k,int i,int large,int index){
    if(i==k) return large;
    int max=INT_MIN;
    int idx=-1;
    for(int j=0;j<v.size();j++){
        if(max<v[j] && v[j]<=large &&j!=index){
            max=v[j];
            idx=j;
        }
    }
    return kthlargest(v,k,i+1,max,idx);    
}
int main(){
    int n=7;
    vector<int>v(n);
    v={4,2,2,2,0,76,1};
    cout<<kthlargest(v,7,0,INT_MAX,-1);


}