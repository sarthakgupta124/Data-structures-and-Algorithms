//min steps complete the tower game on google.
#include <iostream>
// #include<cmath>
using namespace std;
int step(int a){
    if(a==1) return 1;
    // return (pow(2,a-1)+step(a-1));
    return (2*(step(a-1))+1);
}
void path(int n,char a,char b,char c){
    if(n==0) return;
    path(n-1,a,c,b);
    cout<<a<<c<<endl;
    path(n-1,b,a,c);
}
int main(){
    int n;
    cout<<"number of rings";
    cin>>n;
    // cout<<step(n);
    path(n,'A','B','C');

}