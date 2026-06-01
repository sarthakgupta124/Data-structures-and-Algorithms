#include <iostream>
#include<vector>
#include <algorithm>
using namespace std;
int main(){
    vector<int>nums={3,2,3};
    sort(nums.begin(),nums.end());
        int s=(nums.size())/2+1;
        int count=0;
        int ch=nums[0];
        for(int i=0;i<nums.size();i++){
            if(ch==nums[i]) count++;
            if(count>=s){
                cout<<nums[i];
                break;
            }
            if(nums[i]!=ch){
                count=1;
                ch=nums[i];
            }
        }
}