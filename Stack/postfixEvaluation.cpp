#include <iostream>
using namespace std;
#include <stack>
int applyOp(int a, int b, char op) {
    switch(op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': 
            if (b == 0) return 0;
            return a / b;
    }
    return 0;
}
int main(){
    stack<int>values;
    int val1,val2,val;
    string st="79+4*8/3-";
    for(int i=0;i<st.size();i++){
        if(isdigit(st[i])){
            values.push(st[i]-'0');
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