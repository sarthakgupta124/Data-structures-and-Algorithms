#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    int count=0;
    char check=s[0];
    int max=0;
    char g;
    for(int i=0;i<s.length();i++){
        if(check==s[i]) count++;
        
        if(s[i]!=check){
            if(count>max){
                max=count;
                g=check;
            }
            check=s[i];
            count=1;
        }
        
    }
    cout<<g<<":"<<max;
}