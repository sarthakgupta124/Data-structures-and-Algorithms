#include <iostream>
using namespace std;
int po(int a,int b){
    if(b==0) return 1;
    return a*po(a,b-1);

}
int main(){
    cout<<po(2,3);

}