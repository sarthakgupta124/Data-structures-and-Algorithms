#include <iostream>
using namespace std;
#include <stack>
#include<vector>
int main(){
    int k=3;
    int arr[8]={1,-1,5,3,-8,9,9,-5};
    vector<int>ans;
    stack<int> helper;
    for(int i=7;i>=0;i--){
        if(arr[i]<0) helper.push(i);
    }
    int i=0;
    while(i+k<=8){
        if(helper.size()==0) {
            ans.push_back(0);
            i++;
            continue;
        }
        while(helper.top()<i) helper.pop();
        if(helper.top()<i+k && helper.top()>=i) ans.push_back(arr[helper.top()]);
        else ans.push_back(0);
        i++;
    }
    for(int i=0;i<8;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
}