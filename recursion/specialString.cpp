//demo question adobe
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    string s;
    getline(cin,s);
    string output;
    int count=0,i=0;
    while(i<s.length()){
        if(i!=0 && count>0){
            while(count>0){
                if(s[i]=='*'|| s[i]=='$'|| s[i]=='#'){
                    count++;
                    i++;
                }
                else if(s[i]==' ') {
                    i++;
                    output+=' ';
                }
                else{
                    i++;
                    count--;
                }

            }
            count=0;
        }
        if(s[i]=='*'|| s[i]=='$'|| s[i]=='#'){
            count++;
            i++;
        }
        else{
            output=output+s[i];
            i++;
        }
    }
    cout<<output;
    return 0;
}