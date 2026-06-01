// #include <iostream>
// using namespace std;
// void pr(int n,int k){
//     if(n<k) return;
//     cout<<k<<endl;
//     pr(n,++k);
// }
// int main(){
//     pr(5,1);

// }



#include <iostream>
using namespace std;
void pr(int n){
    if(n==0) return;
    pr(n-1);
    cout<<n;

}
int main(){
    pr(5);

}