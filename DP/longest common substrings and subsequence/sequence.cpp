#include <iostream>
#include <string>
using namespace std;
int f(string a,string b,int i,int j){
    if(i>=a.size()||j>=b.size()) return 0;
    if(a[i]==b[j]){
        return 1+f(a,b,i+1,j+1);
    }
    else{
        return max(f(a,b,i+1,j),f(a,b,i,j+1));
    }
}
int main(){
    string a="sarthak";
    string b="gupta";
    cout<<f(a,b,0,0);
    return 0;
}