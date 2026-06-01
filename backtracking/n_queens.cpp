#include<bits/stdc++.h>
using namespace std;
void f(unordered_set<int>&s,int n,int x,vector<int>&ans,int last){
        if(x==0){
            for(int k=0;k<n;k++) cout<<ans[k]<<" ";
            cout<<endl;
            return;
        }

        int current_row = n - x;
        for(int i=0;i<n;i++){
            if(s.count(i)) continue;
            bool ch=false;
            for(int g=0;g<current_row;g++){
                int p_c=ans[g];
                int diff=current_row-g;
                if(i==p_c+diff || i==p_c-diff){
                    ch=true;
                    break;
                }
            }
            if(ch) continue;
            s.insert(i);
            ans.push_back(i);
            f(s,n,x-1,ans,i);
            ans.pop_back();
            s.erase(i);
        }
    }
int main(){
    unordered_set<int>s;
    int n;
    cin>>n;
    vector<int>ans;
    f(s,n,n,ans,-1);
    return 0;
}