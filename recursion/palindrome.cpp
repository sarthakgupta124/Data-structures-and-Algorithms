#include <iostream>
#include <string>
using namespace std;
void palindrome(string org,int f,int l){
    if(f>=l){
        cout<<true;
        return;
    }
    if(org[f]!=org[l]){
        cout<<false;
        return;
    }
    else palindrome(org,f+1,l-1);

}
int main(){
    string s;
    cin>>s;
    palindrome(s,0,s.size()-1);

}