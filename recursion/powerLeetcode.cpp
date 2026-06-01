#include <iostream>
using namespace std;
float powerpos(float a,int b){
    if(b==0) return 1;
    if(b%2==0){
        float p=powerpos(a,b/2);
        return p*p;
    }
    else{
        return a*powerpos(a,b-1);
    }
}
float powerneg(float a,int b){
    if(b==0) return 1;
    if(b%2==0){
        int p=powerneg(a,b/2)/a;
        return p*p;
    }
    else{
        return powerneg(a,b-1)/a;
    }
}

int main(){
    float x=2.1;
    int y=3;
    // cin>>a>>b;
    if(y<0) cout<<powerneg(x,y*(-1));
    else cout<<powerpos(x,y);
    return 0;
}