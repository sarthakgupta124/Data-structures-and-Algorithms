#include <iostream>
#include<vector>
using namespace std;
int main(){
    int n;
    cin>>n;
    bool check=false;
    int low=0,high=n,mid;
    while(low<=high){
        mid=(low+high)/2;
        if((low*low+high*high)==n){
            check=true;
            break;
        }
        else if((low*low+high*high)>n) high--;
        else{
             low+=1;
        }
    }
    if(check==true){
        cout<<low<<" "<<high;
    }
    else{
        cout<<false;
    }
}