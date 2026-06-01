#include <iostream>
#include<string>
#include<vector>
using namespace std;
void storesubset(string ans,string org,vector<string>&v){
    if(org==""){
        v.push_back(ans);
        return;
    }
    char ch=org[0];
    storesubset(ans,org.substr(1),v);
    storesubset(ans+ch,org.substr(1),v);

}
int main(){
    string str="abc";
    vector<string>v;
    storesubset("",str,v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }

}