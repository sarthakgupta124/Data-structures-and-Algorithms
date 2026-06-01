#include <iostream>
#include<vector>
using namespace std;
int main(){
    vector<vector<int>> v;
    int m=3,n=4;
    for(int i=0;i<m;i++){
        vector<int> a;
        for(int j=0;j<n;j++){
            int k;
            cin>>k;
            a.push_back(k);
        }
        v.push_back(a);
    }
    for(int i=0;i<m;i++){
        if(v[i][0]==0){
            for(int j=0;j<n;j++){
                v[i][j]=(!v[i][j]);
            }
        }
    }
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<m;j++){
            if(v[j][i]==1) count++;
            
        }
        if(count<2){
            for(int j=0;j<m;j++){
                v[j][i]=(!v[j][i]);
            }
        }
    }
    int score=0;
    for(int i=0;i<m;i++){
        int x=1;
        for(int j=n-1;j>=0;j--){
            score+=(v[i][j]*x);
            x*=2;
                
        }
        
    }
    cout<<score;

}