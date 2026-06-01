#include <iostream>
using namespace std;
int main(){
    cout<<"enter two number:";
    int x,y;
    cin>>x>>y;
    int pro=1;
    while(y>0){
        pro*=x;
        y-=1;
    }
    cout<<pro;
    return 0;

}