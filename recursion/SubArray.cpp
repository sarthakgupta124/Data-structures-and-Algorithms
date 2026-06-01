#include<iostream>
using namespace std;
#include <vector>

void subArray(vector<int>&a,int index,vector<int>output,bool check){
    if(index==a.size()){
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    if(check==false && output.size()!=0){
        for(int i=0;i<output.size();i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
        return;
    }
    output.push_back(a[index]);
    subArray(a,index+1,output,true);
    output.pop_back();
    subArray(a,index+1,output,false);
}
int main(){
    vector<int>a;
    a={1,2,3,4};
    vector<int>output;
    subArray(a,0,output,true);
    return 0;
}
