#include <iostream>
#include <vector>
using namespace std ;
void merge(vector<int>&a,vector<int>&b,vector<int>&c){
    int i=0,j=0,n=a.size(),m=b.size();
    while(i<n||j<m){
        if(a[i]>b[j]){
            c[i+j]=a[i];
            i++;
        }
        else if(a[i]<b[j]){
            c[i+j]=b[j];
            j++;
        }
        else{
            c[i+j]=a[i];
            i++;
            c[i+j]=b[j];
            j++;

        }
        if(i>=n&&j<m){
            c[i+j]=b[j];
            j++;
        }
        else if(i<n&&j>=m){
            c[i+j]=a[i] ;
            i++;
        }
    }

}
void mergesort(vector<int>&v){
    int k=v.size();
    if(k==1) return;
    int n1=k/2,n2=k-n1;
    vector<int> v1(n1),v2(n2);
    for(int i=0;i<n1;i++) v1[i]=v[i];
    for(int i=0;i<n2;i++) v2[i]=v[i+n1];

    mergesort(v1);
    mergesort(v2);

    merge(v1,v2,v);
}
int main (){
    int n=7;
    vector<int> v(n);
    v={5,0,6,8,2,9,3};
    mergesort(v);
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }

}