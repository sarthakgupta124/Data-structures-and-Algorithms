#include <iostream>
#include<vector>
using namespace std;
void storesubset(string ans,string org,vector<string>&v,bool flag){
    if(org==""){
        v.push_back(ans);
        return;
    }
    char ch=org[0];
    if(org.length()==1){
        if(flag==true) storesubset(ans+ch,org.substr(1),v,true);
        
        storesubset(ans,org.substr(1),v,true);
        return;

    }
    char dh=org[1];
    if(dh==ch){
        if(flag==true) storesubset(ans+ch,org.substr(1),v,true);
        
        storesubset(ans,org.substr(1),v,false);
    }
    else{
        if(flag==true) storesubset(ans+ch,org.substr(1),v,true);
        
        storesubset(ans,org.substr(1),v,true);
    }

}
int main(){
    string str="aab";
    vector<string>v;
    storesubset("",str,v,true);
    for(int i=0;i<v.size();i++) cout<<v[i]<<endl;

}


// #include<iostream>
// using namespace std;
// #include <vector>
// #include <algorithm>
// void path(string st,int i,string trace,bool ch){
//     if(i==st.size()){
//         cout<<trace<<endl;
//         return;
//     }
//     path(st,i+1,trace,true);
//     if(i==0 || st[i]!=st[i-1] || ch==false) path(st,i+1,trace+st[i],false);
// }

// int main(){
//     string s="abaa";
//     sort(s.begin(),s.end());
//     path(s,0,"",true);
//     return 0;
// }
