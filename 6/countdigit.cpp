#include <iostream>
using namespace std;
int main(){
    cout<<"enter No:";
    int x ,c=0;
    cin>>x;

    while(x>0){
        c+=1;
        x=x/10;
    }
    cout<<"digits are "<< c;
}