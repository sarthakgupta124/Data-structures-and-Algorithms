#include <iostream>
#include <stack>
using namespace std;
void display(stack <int>&st){
    if(st.size()==0) return;
    int x=st.top();
    st.pop();
    display(st);
    st.push(x);
    cout<<x<<" ";
}
int main(){
    stack<int> aa;
    aa.push(10);
    aa.push(20);
    aa.push(30);
    aa.push(40);
    aa.push(50);
    display(aa);
}