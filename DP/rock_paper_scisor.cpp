//lecture 5 : 1.10 hrs
#include <iostream>
#include <vector>
using namespace std;
double fr(int r,int s,int p){
    if(r==0) return 0.0;
    if(s==0) return 0.0;
    if(p==0) return 1.0;
    int total=r*s+s*p+p*r;
    double val;
    val=fr(r-1,s,p)*(r*p)/total+fr(r,s-1,p)*(r*s)/total+fr(r,s,p-1)*(s*p)/total;
    return val;

}
double fp(int r,int s,int p){
    if(r==0) return 0.0;
    if(s==0) return 1.0;
    if(p==0) return 0.0;
    int total=r*s+s*p+p*r;
    double val;
    val=fp(r-1,s,p)*(r*p)/total+fp(r,s-1,p)*(r*s)/total+fp(r,s,p-1)*(s*p)/total;
    return val;

}
double fs(int r,int s,int p){
    if(r==0) return 1.0;
    if(s==0) return 0.0;
    if(p==0) return 0.0;
    int total=r*s+s*p+p*r;
    double val;
    val=fs(r-1,s,p)*(r*p)/total+fs(r,s-1,p)*(r*s)/total+fs(r,s,p-1)*(s*p)/total;
    return val;

}
int main(){
    int s=2,r=2,p=2;
    cout<<"probablity of rock:-"<<fr(r,s,p)<<endl;
    cout<<"probablity of paper:-"<<fp(r,s,p)<<endl;
    cout<<"probablity of scisor:-"<<fs(r,s,p)<<endl;
}