#include <iostream>
#include <string>
using namespace std;
string decimalTobinary(int dec){
    string ans="";
    while(dec>0){
        if(dec%2==0) ans='0'+ans;
        else ans='1'+ans;
        dec=dec>>1; //division by 2
    }
    return ans;
}
int main(){
    int y=-5;
    cout<<decimalTobinary(y);

}