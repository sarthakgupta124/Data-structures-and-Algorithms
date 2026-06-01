#include <iostream>
#include <vector>
#include <climits>
using namespace std;
int main(){
    vector<int>arr={0,1,2,3};
    int maxneg=INT_MIN;
    int negpro=1,pospro=1;
    int neg=0,zero=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]==0) zero++;
        else if(arr[i]<0){
            neg++;
            maxneg=max(maxneg,arr[i]);
            negpro*=arr[i];
        }
        else pospro*=arr[i];
    }
    if(neg==0 && zero==0){
        cout<<pospro;
    }
    else if(neg==0 && zero!=0){
        cout<<0;
    }
    else if(neg%2!=0){
        cout<<negpro*pospro;
    }
    else{
        negpro=negpro*(-1)/(maxneg*(-1));
        cout<<negpro*pospro;
    }
        
}