#include <iostream>
#include <vector>
using namespace std;
int main(){
    int n=6;
    vector<int>v(n);
    v={4,7,2,8,1,4};
    for(int i=1;i<n;i++) v[i]+=v[i-1];
    for(int i=0;i<n;i++) cout<<v[i]<<" ";
}