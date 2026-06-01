#include <iostream>
using namespace std;
int fac(int a){
    if(a==1||a==0) return 1;
    int ans=a*fac(a-1);
    return ans;
}
int main(){
    cout<<fac(0);

}