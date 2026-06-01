#include <iostream>
using namespace std;
int sm(int n){
    if(n==0) return 0;
    return n+sm(n-1);

}
int main(){
    cout<<sm(20);

}