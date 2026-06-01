//we use xor since it is commutative property and 0^x=x
#include <iostream>
using namespace std;
int main(){
    int arr[6]={1,3,1,4,4,6};
    int res=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        res^=arr[i];

    }
    cout<<res<<endl;
    int a=0;
    while(true){
        if((res&1)==1){
            break;
        }
        res=res<<1;
        a++;
    }
    int num1=0,num2=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        if((arr[i]<<a)&1==1) num1^=arr[i];
        else num2^=arr[i];

    }
    cout<<num1<<"  "<<num2;
    
}