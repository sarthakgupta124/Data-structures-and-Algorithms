#include <iostream>
using namespace std;
#include <stack>
string applyOp(string a, string b, char op) {
    return a+op+b;
}
int main(){
    stack<string>values;
    string val1,val2,val;
    string st="-/*+79483";
    for(int i=st.size()-1;i>=0;i--){
        if(isdigit(st[i])){
            values.push(to_string(st[i]-'0'));
        }
        else{
            val1=values.top();
            values.pop();
            val2=values.top();
            values.pop();
            val=applyOp(val1,val2,st[i]);
            values.push(val);
        }
    }
    
    cout<<values.top();
    return 0;
}