#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m;
    cout<<"Enter the size of the array: ";
    cin>>n>>m;
    vector<vector<int>>arr(n,vector<int>(m));
    int s=n;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>arr[i][j];
        }
    }
    vector<vector<int>>ans(m,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans[j][i]=arr[i][j];
        }
    }
    for(int i=0;i<m;i++){
        reverse(ans[i].begin(),ans[i].end());
    }
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }

}