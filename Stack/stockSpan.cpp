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
        for(int i=0;i<size;i++){
            cout<<i-aa[i]<<" ";
        }
    }

};
int main(){
    Stack mid;
    Stack ans;
    int dd[]={100,80,60,81,70,60,75,85};
    mid.push(0);
    ans.push(-1);
    for(int i=1;i<8;i++){
        while(mid.len()>0 && dd[mid.top()]<=dd[i]){
            mid.pop();
        }
        if(mid.len()==0) ans.push(-1);
        else ans.push(mid.top());
        mid.push(i);
    }
    ans.print();
    
}