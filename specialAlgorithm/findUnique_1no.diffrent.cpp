//arr=[1,2,3,4,1,2,3,4,6] all element ocur 2 times but 6 1 time hence return 6
//we use xor since it is commutative property and 0^x=x
#include <iostream>
using namespace std;
int main(){
    int arr[5]={1,3,1,4,4};
    int res=0;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++){
        res^=arr[i];

    }
    cout<<res;
}