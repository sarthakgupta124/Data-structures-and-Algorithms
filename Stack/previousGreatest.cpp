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
            cout<<aa[i]<<" ";
        }
    }

};
int main(){
    Stack mid;
    Stack ans;
    int dd[]={8,5,8,1,7,8,10,5,2,1};
    mid.push(dd[0]);
    ans.push(-1);
    for(int i=1;i<10;i++){
        while(mid.len()>0 && mid.top()<=dd[i]){
            mid.pop();
        }
        if(mid.len()==0) ans.push(-1);
        else ans.push(mid.top());
        mid.push(dd[i]);
    }
    ans.print();
    
}