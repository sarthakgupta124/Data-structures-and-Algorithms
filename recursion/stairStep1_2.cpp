//only 1,2 steps are allowed ,it count number of way that person would have to climb stair by 1,2 steps
//it is same like fibonaccci series
#include <iostream>
using namespace std;
int step(int n){
    if(n==1) return 1;
    if(n==2) return 2;
    
    return (step(n-1)+step(n-2));
}
int main(){
    cout<<"number of ways:"<<step(5);

}