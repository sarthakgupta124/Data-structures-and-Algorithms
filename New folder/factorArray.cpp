// distinct prime factor in array
// class Solution {
// public:
//     int distinctPrimeFactors(vector<int>& nums) {
//         int max=INT_MIN;
//         for(int i=0;i<nums.size();i++){
//             if(max<nums[i]) max=nums[i];
//         }
//         vector<int>sieve(max+1,1);
//         for(int i=2;i<=sqrt(max);i++){
//             if(sieve[i]==1){
//                 for(int j=2*i;j<=max;j+=i) sieve[j]=0;
//             }
//         }
//         vector<int> new_sieve;
//         for(int i=2;i<=max;i++) if(sieve[i]==1) new_sieve.push_back(i);
//         int count=0;
//         for(int i=0;i<new_sieve.size();i++){
//             for(int j=0;j<nums.size();j++){
//                 if(nums[j]%new_sieve[i]==0){
//                     count+=1;
//                     break;
//                 }
//             }
//         }
//         return count;
        
//     }
// };