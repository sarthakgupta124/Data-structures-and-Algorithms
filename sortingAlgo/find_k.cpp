#include <iostream>
using namespace std;
float min(float a,float b){
    if(a>=b) return b;
    else return a;
}
float max(float a,float b){
    if(a<=b) return b;
    else return a;
}
int main(){
    int n=4,arr[n]={5,3,10,3};
    float kmin=INT16_MIN,kmax=INT16_MAX;
    for(int i=0;i<n-1;i++){
        if((arr[i+1]-arr[i])>=0){
            kmax=min(kmax,(arr[i+1]+arr[i])/2.0);
            
        }
        else{
            kmin=max(kmin,(arr[i+1]+arr[i])/2.0);
        }
    }
    int a=0,b=0;
    if(kmax==((int)kmax));
    else kmax=((int)kmax);
    if(kmin==((int)kmin));
    else kmin=((int)kmin)+1;
    if(kmax<kmin) cout<<"-1";
    else{
        cout<<"range of k is: ["<<kmin<<","<<kmax<<"]";
    }
    
}