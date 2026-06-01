//min number of flip req to convert one number to other
#include <iostream>
using namespace std;
int main(){
    int x=32,y=23;
    int count=0;
    int k=x^y;
    //now count number of 1 in k to get no. of flip
    while(k>0){
        count++;
        k=k&(k-1);
    }
    cout<<count;

}