#include <iostream>
#include <stack>
using namespace std;
void push_bottom(stack<int>&st,int val){
    if(st.size()==0){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    push_bottom(st,val);
    st.push(x);
}
void reverse(stack<int>&st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    reverse(st);
    push_bottom(st,x);
}
void print(stack<int>&st){
    stack <int>temp;
    while(st.size()>0){
        temp.push(st.top());
        st.pop();
    }
    cout<<endl;
    while(temp.size()>0){
        cout<<temp.top()<<" "; // prints in normal
        st.push(temp.top());
        temp.pop();
    }
}
int main(){
    stack<int>aa;
    aa.push(10);
    aa.push(20);
    aa.push(30);
    aa.push(40);
    aa.push(50);
    reverse(aa);
    print(aa);
}