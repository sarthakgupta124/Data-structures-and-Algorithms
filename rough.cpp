#include<bits/stdc++.h>
using namespace std;    
int main(){
    string t;
    cin>>t;
    unordered_map<char,pair<int,int>>ft;
    for(int i=0;i<t.size();i++) ft[t[i]].first++;
    for(auto i:ft){ 
        cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<endl;
    }
}