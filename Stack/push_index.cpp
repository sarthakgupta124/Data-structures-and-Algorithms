#include <iostream>
#include <stack>
using namespace std;
void recursion_index(stack<int>&st,int idx,int val){
    if(st.size()==idx){
        st.push(val);
        return;
    }
    int x=st.top();
    st.pop();
    recursion_index(st,idx,val);
    st.push(x);

}
void push_index(stack<int>&st,int idx,int val){
    stack<int> temp;
    while(st.size()>idx){
        temp.push(st.top());
        st.pop();
    }
    st.push(val);
    while(temp.size()>0){
        st.push(temp.top());
        temp.pop();
    }
    return;

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
    push_index(aa,2,5);
    print(aa);
    // recursion_index(aa,2,5);
    // print(aa);
}