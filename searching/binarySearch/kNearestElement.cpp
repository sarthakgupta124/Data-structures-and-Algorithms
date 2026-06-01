class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int low=0,high=arr.size()-1,mid;
        bool ch=false;
        while(low<=high){
            mid=(low+high)/2;
            if(arr[mid]==x){
                ch=true;
                break;
            }
            else if(arr[mid]>x) high=mid-1;
            else low=mid+1;
        }
        int i,j;
        
        vector<int> sol;
        if(ch==true){
            sol.push_back(arr[mid]);
            i=(mid-1),j=(mid+1);
            k-=1;
        }
        else{
            k=k;
            i=(low-1),j=(low);
        }
        while(k>0 &&(i>=0||j<arr.size())){
            if(i>=0&&j<arr.size()){
                int a=x-arr[i],b=x-arr[j];
                if(a<0) a=(-a);
                if(b<0) b=(-b);
                if(a>b){
                    sol.push_back(arr[j]);
                    j++;
                }
                else if(a==b){
                    sol.push_back(arr[i]);
                    i--;
                }
                else{
                    sol.push_back(arr[i]);
                    i--;
                }
            }
            else{
                if(i<0 &&j<arr.size()){
                    sol.push_back(arr[j]);
                    j++;
                }
                else{
                    sol.push_back(arr[i]);
                    i--;
                }
            }
            k--;
        }
        sort(sol.begin(),sol.end());
        return sol;
        
    }
};