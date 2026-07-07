#include <bits/stdc++.h>
using namespace std;
string getPermutation(string s, int k, string ans = ""){
    if(s.size() == 1){
        return ans + s;
    }
    int fact=1;
    for(int i=1; i<s.size(); i++){
        if(fact*i > k) break;
        fact *= i;
    }
    int index = (k-1) / fact;
    return getPermutation(s.substr(0, index) + s.substr(index+1), k % fact, ans + s[index]);
}
int main(){
    int n;
    cin >> n;
    string s = "";
    for(int i = 1; i <= n; i++){
        s += to_string(i);
    }
    int k;
    cin >> k;
    cout << getPermutation(s, k) << endl;
}