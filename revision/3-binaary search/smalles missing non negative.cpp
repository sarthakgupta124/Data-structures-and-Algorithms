#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;
    vector<int>v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    //ex:v= {0,1,2,3,4,5,6,7,8,9}
    int l=0,h=v.size()-1;
    while(l<=h){
        int mid=l+(h-l)/2;
        if(v[mid]==mid) l=mid+1;
        else h=mid-1;
    }
    cout<<"The smallest missing non-negative integer is: "<<l;
}