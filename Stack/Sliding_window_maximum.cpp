#include<iostream>
using namespace std;
#include <stack>
#include <vector>
int main(){
    vector<int>val;
    val={1,3,-1,-3,5,3,6,7};

    // for(int i=0;i<val.size();i++) cout<<val[i]<<" ";
    vector<int>max_index;
    stack<int>helper;
    
    max_index.push_back(val.size());
    helper.push(val.size()-1);
    for(int i=val.size()-2;i>=0;i--){
        while(helper.size()!=0 && val[helper.top()]<val[i]) helper.pop();
        if(helper.size()==0) max_index.push_back(val.size());
        else max_index.push_back(helper.top());
        helper.push(i);

    }
    for(int i=0;i<max_index.size();i++) cout<<val[max_index[i]]<<" ";

}