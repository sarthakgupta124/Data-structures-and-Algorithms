#include <iostream>
#include <vector>
using namespace std;
class Stack{ //user define datastructure
public:
    vector<int>arr;
    Stack(){
    }
    void push(int val){
        //no overflow condition
        arr.push_back(val);
    }
    void pop(){
        if(arr.size()==0){
            cout<<"stack underflow"<<" ";
        }
        else
            arr.pop_back();
    }
    int top(){
        return arr[arr.size()-1];
    }
    int size(){
        return arr.size();
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
