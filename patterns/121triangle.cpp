#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=1;
        for(int j=1;j<=(n-i);j++){
            cout<<" ";
        }
        for(int j=1;j<=(i-1);j++){
            cout<<a;
            a++;

        }
        for(int j=1;j<=(i);j++){
            cout<<a;
            a--;

        }

        cout<<endl;

    }
}