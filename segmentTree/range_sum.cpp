#include <bits/stdc++.h>
using namespace std;
vector<int>st;
void buildTree(int arr[],int lo,int hi,int i){
    if(lo==hi){
        st[i]=arr[lo];
        return;
    }
    int mid=(lo+hi)/2;
    buildTree(arr,lo,mid,2*i+1);
    buildTree(arr,mid+1,hi,2*i+2);
    st[i]=st[2*i+1]+st[2*i+2];
}
int getSum(int i,int lo,int hi,int l,int r){

    if(l>hi || r<lo) return 0;
    else if(l<=lo && hi<=r) return st[i];
    else{
        int mid=(lo+hi)/2;
        return getSum(2*i+1,lo,mid,l,r)+getSum(2*i+2,mid+1,hi,l,r);
    }
}
int main(){
    int arr[]={1,4,2,8,6,4,9,3};
    int n=sizeof(arr)/4;
    st.resize(4*n);
    buildTree(arr,0,n-1,0);
    int l,r;
    cout<<"Enter the range:";
    cin>>l>>r;
    cout<<getSum(0,0,n-1,l,r);
}