#include<iostream>
using namespace std;
int n;
int print(int x){
    int a=n-x+1;
    if(a<0) cout<<(-a);
    else cout<<a;

}
int main(){
    cout<<"enter value of n:";
    cin>>n;
    int k=n;
    for(int i=1;i<=(n);i++){
        for(int j=1;j<=(n);j++){
            if(i<j) print(i);
            else if (j<=i) print(j);
        }
        for(int j=n-1;j>=(1);j--){
            if(i<j) print(i);
            else if (j<=i) print(j);
        }
        cout<<endl;

    }
    for(int i=n-1;i>=(1);i--){
        for(int j=1;j<=(n);j++){
            if(i<j) print(i);
            else if (j<=i) print(j);
        }
        for(int j=n-1;j>=(1);j--){
            if(i<j) print(i);
            else if (j<=i) print(j);
        }
        cout<<endl;

    }
}