#include <iostream>
#include <vector>
using namespace std;
void combinationSum(vector<int>& candidates, int target,vector<vector<int>>&solution,vector<int> ans,int k) {
    if(target==0){
        solution.push_back(ans);
        return;
    }
    else if(target<0){
        return;
    }
    for(int i=k;i<candidates.size();i++){
        
        ans.push_back(candidates[i]);
        combinationSum(candidates,target-candidates[i],solution,ans,i);
        ans.pop_back();
    }


}
int main(){
    int tar;
    cin>>tar;
    vector<vector<int>> soll;
    vector<int> anss;
    vector<int> candidates;
    candidates={2,3,6,7};
    
    combinationSum(candidates,tar,soll,anss,0);
    for(int i=0;i<soll.size();i++){
        for(int j=0;j<soll[i].size();j++){
            cout<<soll[i][j]<<" ";
        }
        cout<<endl;
    }

}