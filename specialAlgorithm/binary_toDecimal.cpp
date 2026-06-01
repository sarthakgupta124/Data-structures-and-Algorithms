#include <iostream>
#include <string>
using namespace std;
int binaryTodecimal(string &binary){
    //1<<x it work asss 2 to power x
    int x=0;
    int sum=0;
    for(int i=binary.size()-1;i>=0;i--){
        char ch=binary[i];
        int num=ch-'0';
        sum+=num*(1<<x);
        x++;
    }
    return sum;
}
int main(){
    string str="00111";
    cout<<binaryTodecimal(str);

}