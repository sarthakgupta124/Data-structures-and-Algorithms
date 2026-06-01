#include <iostream>
#include <vector>
using namespace std;
void merge(vector<int>&v1,vector<int>&v2,vector<int>&v){
    int x=v1.size(),y=v2.size(),i=0,j=0;
    while(i<x||j<y){
        if(v1[i]>v2[j]){
            v[i+j]=v2[j];
            j++;
        }
        else if(v1[i]<v2[j]){
            v[i+j]=v1[i];
            i++;
        }
        else{
            v[i+j]=v2[j];
            j++;
            v[i+j]=v1[i];
            i++;
        }
        if(i>=x&&j<y){
            v[i+j]=v2[j];
            j++;
        }
        else if(i<x&&j>=y){
            v[i+j]=v1[i];
            i++;
        }
    }
    return;

}
int mergesort(vector<int>&v){
    int count=0;
    int k=v.size();
    int n1=k/2,n2=k-n1;
    if(k==1) return count;
    vector<int>v1(n1),v2(n2);
    for(int i=0;i<n1;i++) v1[i]=v[i];
    for(int i=0;i<n2;i++) v2[i]=v[n1+i];

    count+=mergesort(v1);
    count+=mergesort(v2);
    int i=0,j=0;
    while(i<v1.size()&&j<v2.size()){
        if(v2[j]>v1[i]) i++;
        else if(v2[j]<v1[i]) {
            count+=v1.size()-i;
            j++;
        }
    }

    merge(v1,v2,v);
    v1.clear();
    v2.clear();
    return count;


}
int main(){
    int n=5;
    vector<int>k(n);
    k={8,4,9,2,0};
    cout<<mergesort(k)<<endl;
    for(int i=0;i<n;i++) cout<<k[i]<<" ";
    

}