//set are number of 1 in binary representaion of number
#include <iostream>
#include <string>
using namespace std;
int setbit(int num){
    return __builtin_popcount(num);  //built in function
}
int main(){
    int y=4;
    cout<<setbit(y);

} 