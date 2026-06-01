//without any two consicutive one
#include <iostream>
#include <string>
using namespace std;
bool binary(int n,string last,string ans,bool a){
    if(n==0){
        cout<<ans<<endl;
        return true;
    }
    if(last=="0" || last=="") binary(n-1,last="1",ans+"1",a);
    binary(n-1,last="0",ans+"0",a);



}
int main(){
    int n;
    cin>>n;
    binary(n,"","",false);
}