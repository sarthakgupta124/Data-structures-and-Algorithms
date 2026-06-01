#include<iostream>
using namespace std;
int main(){
    int x=453;
    int y;
    int count=0;
    while(x>0){
        y=x-1;
        count++;
        x=x&y;  
    }
    cout<<count;
}