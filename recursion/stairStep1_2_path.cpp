#include<iostream>
using namespace std;
#include <vector>
string path(int n,string path_trace=""){
    if(n==1){
        path_trace+="1";
        cout<<path_trace<<endl;
        return path_trace;
    }
    if(n==0){
        cout<<path_trace<<endl;
        return path_trace;
    }

    return path(n-1,path_trace+"1") + path(n-2,path_trace+"2");
    
}

int main(){
    path(4);
    return 0;
}
