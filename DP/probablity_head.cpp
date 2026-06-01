//lecture 4 //10 min
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
double f(vector<double>&p,int i,int x){
    if(x==0) return 1;
    if(i<0) return 0;
    return f(p,i-1,x-1)*p[i]+f(p,i-1,x)*(1-p[i]);

}
int main(){
    vector<double>p;
    p={0.3,0.6,0.8};
    cout<<fixed<<setprecision(9)<<f(p,3-1,3/2+1); // sets the precision of the output to 9 decimal places
    return 0;
}