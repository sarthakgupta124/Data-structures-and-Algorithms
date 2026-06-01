class Solution {
public:
    vector<vector<string>> ass;
    void f(unordered_set<int>&s,int n,int x,vector<string>&ans){
        if(x==0){
            ass.push_back(ans);
            return;
        }
        int current_row = n - x;
        for(int i=0;i<n;i++){
            if(s.count(i)) continue;
            bool ch=false;
            for(int g=0;g<current_row;g++){
                int p_c;
                for(p_c=0;p_c<ans[g].size();p_c++) if(ans[g][p_c]=='Q') break;
                int diff=current_row-g;
                if(i==p_c+diff || i==p_c-diff){
                    ch=true;
                    break;
                }
            }
            if(ch) continue;
            s.insert(i);
            ans.push_back(i);
            ans[current_row][i]='Q';
            f(s,n,x-1,ans);
            ans[current_row][i]='.';
            s.erase(i);
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        unordered_set<int>s;
        vector<string>ans(n,string s(n, '.'));
        f(s,n,n,ans);
        return ass;
    }
};