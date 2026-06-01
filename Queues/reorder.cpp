// #include <iostream>
// using namespace std;
// #include <queue>
// #include<stack>
// void push_bottom(stack<int>&st,int val){
//     if(st.size()==0){
//         st.push(val);
//         return;
//     }
//     int x=st.top();
//     st.pop();
//     push_bottom(st,val);
//     st.push(x);
// }
// void reverse(stack<int>&st){
//     if(st.size()==0) return;
//     int x=st.top();
//     st.pop();
//     reverse(st);
//     push_bottom(st,x);
// }
// void display(queue<int>q){
//     int s=q.size();
//     for(int i=0;i<s;i++){
//         cout<<q.front()<<" ";
//         q.pop();
//     }
//     cout<<endl;
// }
// int main(){
//     queue<int>q;
//     for(int i=1;i<=8;i++){
//         q.push(i);
//     }
//     display(q);
//     stack<int>helper;
//     for(int i=1;i<=8;i++){
//         if(i<=4){
//             q.push(q.front());
//             q.pop();
//         }
//         else{
//             helper.push(q.front());
//             q.pop();
//         }
//     }
//     reverse(helper);
//     for(int i=0;i<8;i++){
//         if(i%2==0){
//             q.push(q.front());
//             q.pop();
//         }
//         else{
//             q.push(helper.top());
//             helper.pop();
//         }
//     }
//     display(q);
// }


//method 2

#include <iostream>
using namespace std;
#include <queue>
#include<stack>
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
void display(queue<int>q){
    int s=q.size();
    for(int i=0;i<s;i++){
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
}
int main(){
    queue<int>q;
    for(int i=1;i<=8;i++){
        q.push(i);
    }
    display(q);
    stack<int>helper;
    for(int i=0;i<4;i++){
        helper.push(q.front());
        q.pop();
    }
    for(int i=0;i<4;i++){
        q.push(helper.top());
        helper.pop();
    }
    for(int i=0;i<4;i++){
        helper.push(q.front());
        q.pop();
    }
    for(int i=0;i<4;i++){
        q.push(helper.top());
        helper.pop();
        q.push(q.front());
        q.pop();
    }

    //now reversing the whole queue
    for(int i=0;i<8;i++){
        helper.push(q.front());
        q.pop();
    }
    for(int i=0;i<8;i++){
        q.push(helper.top());
        helper.pop();
    }
    display(q);
}