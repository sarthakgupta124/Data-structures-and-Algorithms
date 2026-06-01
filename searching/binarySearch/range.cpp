class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            
            int i=-1,j=-1;
            if(nums.size()==1){
                if(nums[0]==target){
                    i=0;
                    j=0;
                }
            }
            else{
                int low=0,high=nums.size()-1,mid;
                bool lower=false;
                while(low<=high){
                    mid=low+(high-low)/2;
                    if(nums[mid]==target){
                        if(lower==false){
                            if(mid>0&&nums[mid-1]==nums[mid]){
                                high=mid-1;
                            }
                            else{
                                i=mid;
                                lower=true;
                                low=mid;
                                
                            }
                        }
                        else{
                            if(mid<nums.size()-1 && nums[mid+1]==nums[mid]){
                                if(high>=nums.size()-1){
                                    low=mid+1;
                                }
                                else{
                                    high+=1;
                                }
                            }
                            else if(mid>=nums.size()-1 && nums[mid]==target){
                                j=mid;
                                break;

                            }
                            else{
                                j=mid;
                                break;
                            }
                            if(high>nums.size()-1){
                                j=--high;
                                break;
                            }
                        }
                    }
                    else if(nums[mid]>target) high=mid-1;
                    else low=mid+1;
                }
            }

            return {i,j};
        }
            
};