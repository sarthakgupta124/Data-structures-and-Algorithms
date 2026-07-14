#include <iostream>
#include <vector>
using namespace std;
int partition(vector<int>&k,int a,int b){
    int pivot=a,co=0;

    for(int i=a+1;i<b;i++){
        
        if(k[i]<k[a]) co++;
    }
    swap(k[a],k[a+co]);
    int i=a,j=b;
    while(i<(a+co) && (j>a+co)){
        if(k[i]<=k[a+co]) {
            i++;   
        }
        else if(k[j]>=k[a+co]) {
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
void ouicksort(vector<int>&v,int i,int j){
    if(i>=j) return;
    int c=partition(v,i,j);
    ouicksort(v,i,c);
    ouicksort(v,c+1,j);
    
}
int main(){
    int n=10;
    vector<int> v(n);
    v={5,15,100,6,1,785,0,99,2,55};

    ouicksort(v,0,n);
    for(int i=0;i<n;i++) cout<<v[i]<<" ";

}