#include<bits/stdc++.h>
using namespace std;
void permutation(string &str,int idx){
    if(idx==str.size()-1){
        cout<<str<<endl;
        return;
    }
    unordered_set<char>s;
    for(int i=idx;i<str.size();i++){
        if(s.count(str[i])) continue; //pruning
        s.insert(str[i]); 
        swap(str[i],str[idx]);
        permutation(str,idx+1);
        swap(str[i],str[idx]); //backtracking
    }
}
int main(){
    string str="aba";
    permutation(str,0);
    return 0;
}