#include <iostream>
using namespace std;
class Stack{ //user define datastructure
public:
    int arr[5];
    int idx;
    Stack(){
        idx=-1;
    }
    void push(int val){
        if(idx==4){
            cout<<"stack overflow"<<" ";
        }
        else arr[++idx]=val;
    }
    void pop(){
        if(idx==-1){
            cout<<"stack underflow"<<" ";
        }
        else
            idx--;
    }
    int top(){
        return arr[idx];
    }
    int size(){
        return idx+1;
    }
};
int main(){
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    cout<<st.size();
}
