#include <iostream>
#include <string>
using namespace std;
void func(string org,string ans,int x){
    if(org[x]!='a') ans+=org[x];
    if(x==org.size()){
        cout<<ans;
        return;
    }
    func(org,ans,++x);
}
int main(){
    func("sarthak","",0);

}