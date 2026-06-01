#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
int main(){
    int m=6,n=4;
    vector<int>x={2,1,3,1,4};
    vector<int>y={4,1,2};
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int horSection=1;
    int verSection=1;
    int cost=0;
    int i=x.size()-1;
    int j=y.size()-1;
    while(i>=0 && j>=0){
        if(x[i]>y[j]){
            cost+=verSection*x[i];
            i--;
            horSection++;
        }
        else if(x[i]<y[j]){
            cost+=horSection*y[j];
            j--;
            verSection++;
        }
        else{
            if(x[i]*verSection<y[j]*horSection){
                cost+=verSection*x[i];
                i--;
                horSection++;
            }
            else{
                cost+=horSection*y[j];
                j--;
                verSection++;
            }
        }
    }
    while(i>=0){
        cost+=verSection*x[i];
        i--;
        horSection++;
    }
    while(j>=0){
        cost+=horSection*y[j];
        j--;
        verSection++;
    }
    cout<<cost;
}