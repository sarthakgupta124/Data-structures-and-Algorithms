#include <iostream>
#include<string>
#include<vector>
using namespace std;
void permutation(string ans,string org){
    if(org==""){
        cout<<ans<<endl;
        return;
    }
    for(int i=0;i<org.length();i++){
        char ch=org[i];
        string left=org.substr(0,i);
        string right=org.substr(i+1);
        permutation(ans+ch,left+right);
    }

}
int main(){
    string str="abc";
    int n=3;
    permutation("",str);

}