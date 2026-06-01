#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int,int> pp;
bool cmp(pp &a,pp &b){
    double r1=(a.first*1.0)/(a.second*1.0);
    double r2=(b.first*1.0)/(b.second*1.0);
    return r1>r2;
}
double fractionalknapsack(vector<int>&profit,vector<int>&wieght,double &capacity){
    vector<pp>rv;
    for(int i=0;i<profit.size();i++){
        rv.push_back({profit[i],wieght[i]});
    }
    sort(rv.begin(),rv.end(),cmp);
    double result=0;
    for(int i=0;i<=rv.size();i++){
        if(capacity>=rv[i].second){
            result+=rv[i].first;
            capacity-=rv[i].second;
        }
        else if(capacity>0){
            result=result+(rv[i].first)*1.0/(rv[i].second)*1.0*capacity;
            capacity=0;
        }
        else break;
    }
    return result;
}
int main(){
    vector<int>profit={60,100,120};
    vector<int>wieght={10,20,30};
    double capacity=50;
    double res=fractionalknapsack(profit,wieght,capacity);
    cout<<res;
}