#include <iostream>
using namespace std;
#include <stack>
string applyOp(string a, string b, char op) {
    return a+op+b;
}
int main(){
    stack<string>values;
    string val1,val2,val;
    string st="79+4*8/3-";
    for(int i=0;i<st.size();i++){
        if(isdigit(st[i])){
            values.push(to_string(st[i]-'0'));
        }
        else{
            val2=values.top();
            values.pop();
            val1=values.top();
            values.pop();
            val=applyOp(val1,val2,st[i]);
            values.push(val);
        }
    }
    
    cout<<values.top();
    return 0;
}