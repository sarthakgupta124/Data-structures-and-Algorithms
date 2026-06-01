#include<iostream>
using namespace std;
void make1(int* n){
    //this makes every digit 1 of whole in binary form
    *n=*n|(*n>>1);
    *n=*n|(*n>>4);
    *n=*n|(*n>>8);
    *n=*n|(*n>>2);
    *n=*n|(*n>>16);
    return ;
}
int main(){
    //using xor operator with 1-diffrent input 0-on same input
    int n=4;
    int y=n;
    make1(&n);
    cout<<(n^y);
}