#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>&k,int a,int b){
    int pivot=(a+b)/2,co=0;//we take random pivot point to improve time complexity

    for(int i=a;i<b;i++){
        if(i==pivot) continue;
        if(k[i]<k[pivot]) co++;
    }
    swap(k[pivot],k[a+co]);
    int i=a,j=b;
    while(i<(a+co) && (j>a+co)){
        if(k[i]<=k[a+co]) {
            i++;   
        }
        else if(k[j]>k[a+co]) {
            j--;
        }
        else{
            swap(k[i],k[j]);
            i++;
            j--;
        }
    }
    return (a+co);

}
int kthsmallest(vector<int>&v,int i,int j,int k){
    int c=partition(v,i,j);
    if(c==k) return v[c] ;
    else if(c<k)  kthsmallest(v,c+1,j,k);
    else{
         kthsmallest(v,i,c,k);
    }
}
int main(){
    int n=5;
    int k=2;
    vector<int> v(n);
    v={5,15,100,6,1};

    cout<<kthsmallest(v,0,n,k-1)<<endl;
    for(int i=0;i<n;i++) cout<<v[i]<<" ";

}