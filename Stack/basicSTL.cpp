#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.size()<<endl;
    st.pop();
    cout<<st.size()<<endl;
    cout<<st.top()<<endl;
    st.push(50);

    // printing stack in reverse order -->emptying the stack
    // while(st.size()>0){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    //using extra stack
    stack <int>temp;
    while(st.size()>0){
        temp.push(st.top());
        cout<<st.top()<<" ";//reverse order
        st.pop();
    }
    cout<<endl;
    while(temp.size()>0){
        cout<<temp.top()<<" "; // prints in normal
        st.push(temp.top());
        temp.pop();
    }
}
