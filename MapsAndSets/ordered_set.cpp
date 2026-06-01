#include <iostream>
#include <set>
#include<map>
using namespace std;
int main(){
    set<int>a;
    a.insert(9);
    a.insert(1);
    a.insert(7);
    for(auto x:a)
        cout<<x<<" ";
    cout<<endl;
    map<int,int>m;
    m[2]=5;
    m[1]=9;
    m[3]=6;
    for(auto ele:m){
        cout<<ele.first<<" "<<ele.second<<endl;
    }
}