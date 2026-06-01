#include <iostream>
#include <string>
using namespace std;
void paranthesis(int x,int open,int close,string ans){
    if(close==x && open==x) {
        cout<<ans<<endl;
        return;
    }
    
    if(open<x)paranthesis(x,open+1,close,ans+"(");
    if(open>close && close<x) paranthesis(x,open,close+1,ans+")");
    
}
int main(){
    int n;
    cin>>n;
    paranthesis(n,0,0,"");
}