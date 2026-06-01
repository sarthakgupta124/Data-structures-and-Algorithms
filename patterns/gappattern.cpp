#include <iostream>
using namespace std;
int main(){
    int n;
    cout<<"enter value of n:";
    cin>>n;
    for(int i=1;i<=n;i++){
        int a=1;
        if(i==1){
            for(int j=1;j<=2*n-1;j+=1){
                cout<<a;
                a++;
            }
            cout<<endl;
            a=1;
        }
        
        for(int j=1;j<=(n-i);j+=1){
            cout<<a;
            a++;
        }
        for(int j=1;j<=(2*i-1);j+=1){
            cout<<" ";
            a++;
        }
        for(int j=1;j<=(n-i);j+=1){
            cout<<a;
            a++;
        }


        cout<<endl;

    }

}