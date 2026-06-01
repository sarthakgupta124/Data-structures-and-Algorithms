#include <iostream>
#include <string>
using namespace std;
string max_str(string s1, string s2, string s3) {
    if (s1.size() >= s2.size() && s1.size() >= s3.size()) return s1;
    if (s2.size() >= s1.size() && s2.size() >= s3.size()) return s2;
    return s3;
}
string f(string a,string b,int i,int j,string s){
    if(i>=a.size()||j>=b.size()) return s;
    if(a[i]==b[j]){
        return f(a,b,i+1,j+1,s+a[i]);
    }
    else{
        string s1=f(a,b,i+1,j,"");
        string s2=f(a,b,i,j+1,"");
        return max_str(s, s1, s2);
    } 
}
int main(){
    string a="sarthak";
    string b="gupta";
    cout<<f(a,b,0,0,"");
    return 0;
}