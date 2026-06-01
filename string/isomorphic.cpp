wrong code
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string check(string str ){
    string k="";
    sort(str.begin(),str.end());
    int count=0;
    char ch=str[0];
    for(int i=0;i<str.size();i++){
        if(ch==str[i]) count++;
        if(ch!=str[i]){
            k+=to_string(count);
            count=1;
            ch=str[i];
        }
    }
    k+=to_string(count);
    return k;

}
int main(){
    string s,t;
    cin>>s>>t;
    string s1=check(s);
    string s2=check(t);
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if(s1==s2) cout<<"true";
    else cout<<"false";
}