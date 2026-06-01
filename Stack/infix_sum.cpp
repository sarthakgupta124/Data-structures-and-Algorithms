#include <iostream>
using namespace std;
#include <stack>
int getPriority(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}
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
    stack<char>oper;
    stack<int>values;
    int val1,val2,val;
    string st="2+4*6/8-3";
    for(int i=0;i<st.size();i++){
        if(isdigit(st[i])){
            values.push(st[i]-'0');
        }

        else if(oper.size()==0 || getPriority((char)st[i])>getPriority(oper.top())){
            oper.push(st[i]);
        }
        else{
            while(oper.size()!=0 && getPriority((char)st[i])<=getPriority(oper.top())){

                val2=values.top();
                values.pop();
                val1=values.top();
                values.pop();
                val=applyOp(val1,val2,oper.top());
                oper.pop();
                int s=(int) val;
                values.push(s);
            }

            oper.push(st[i]);
        }
    }
    while(oper.size()!=0){
        val2=(int)values.top();
        values.pop();
        val1=(int)values.top();
        values.pop();
        val=applyOp(val1,val2,oper.top());
        values.push(val);
        oper.pop();
    }
    cout<<values.top();
    return 0;
}