#include<iostream>
using namespace std;
int maxpower2(int n){
    n=n|(n>>1);
    n=n|(n>>2);
    n=n|(n>>4);
    n=n|(n>>8);
    n=n|(n>>16);
    return (n+1)/2;
}
int main(){
    int x=90;
    int y;
    int count=0;
    int last;
    while(x>0){
        y=x-1;
        count++;
        last=x;
        x=x&y;  
    }
    int s=90;
    cout<<last;
    cout<<maxpower2(s);
}