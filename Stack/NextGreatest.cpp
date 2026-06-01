#include <iostream>
#include <vector>
using namespace std;
class Stack{
public:
    vector<int>aa;
    int size;
    Stack(){
        size=0;
    }
    void push(int k){
        aa.push_back(k);
        size++;
    }
    int len(){
        return size;
    }
    int top(){
        return aa[size-1];
    }
    void pop(){
        aa.pop_back();
        size--;
    }
    void print(){
        for(int i=size-1;i>=0;i--){
            cout<<aa[i]<<" ";
        }
    }

};
int main(){
    Stack mid;
    Stack ans;
    int dd[]={8,5,8,1,7,8,10,5,2,1};
    //pop,ans,push
    mid.push(dd[sizeof(dd)/sizeof(dd[0])-1]);
    ans.push(-1);
    for(int i=10-2;i>=0;i--){
        while(mid.len()>0 && mid.top()<=dd[i]){
            mid.pop();
        }
        if(mid.len()==0) ans.push(-1);
        else ans.push(mid.top());
        mid.push(dd[i]);
    }
    ans.print();
    
}