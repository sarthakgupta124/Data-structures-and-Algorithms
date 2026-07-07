#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<string>v;
    int n;
    cout<<"Enter the number of words: ";
    cin>>n;
    cout<<"Enter the words: ";
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        v.push_back(s);
    }
    int count=0;
    string ans="";
    unordered_map<string,int>mp;
    for(int i=0;i<n;i++){
        mp[v[i]]++;
        if(mp[v[i]]>count){
            count=mp[v[i]];
            ans=v[i];
        }
    }
    cout<<"The most occurred word is: "<<ans<<" with frequency: "<<count<<endl;
}