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
string applyOp(string a, string b, char op) {
    // switch(op) {
    //     case '+': return "+ab";
    //     case '-': return f"-{a}{b}";
    //     case '*': return "*ab";
    //     case '/':
    //         return "/ab";
    // }
    return op+a+b;
}
int main(){
    stack<char>oper;
    stack<string>values;
    string val1,val2;
    string val;
    string st="(7+9)*4/8-3";
    for(int i=0;i<st.size();i++){
        if(isdigit(st[i])){
            values.push(to_string(st[i]-'0'));
        }
        else if(st[i]=='('){
            oper.push(st[i]);
        }
        else if(st[i]==')'){
            while(oper.top()!='('){
                val2=values.top();
                values.pop();
                val1=values.top();
                values.pop();
                val=applyOp(val1,val2,oper.top());
                oper.pop();
                values.push(val);
            }
            oper.pop();
        }

        else if(oper.size()==0 || oper.top()=='(' || getPriority((char)st[i])>getPriority(oper.top())){
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
                values.push(val);
            }

            oper.push(st[i]);
        }
    }
    while(oper.size()!=0){
        val2=values.top();
        values.pop();
        val1=values.top();
        values.pop();
        val=applyOp(val1,val2,oper.top());
        values.push(val);
        oper.pop();
    }
    cout<<values.top();
    // cout<<applyOp("3","5",'+');
    return 0;
}