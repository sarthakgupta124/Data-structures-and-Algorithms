#include<bits/stdc++.h>
using namespace std;
void permutation(string str,string ans){
    if(str==""){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<str.size();i++){
        string left=str.substr(0,i);
        string right=str.substr(i+1);
        permutation(left+right,ans+str[i]);
    }
}
int main(){
    permutation("abc","");
    return 0;
}