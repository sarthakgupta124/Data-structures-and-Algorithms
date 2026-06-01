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
    string st="-/*+79483";
    for(int i=st.size()-1;i>=0;i--){
        if(isdigit(st[i])){
            values.push(st[i]-'0');
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