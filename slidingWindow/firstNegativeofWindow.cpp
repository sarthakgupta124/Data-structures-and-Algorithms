#include <iostream>
#include <vector>
using namespace std;
int main(){
    int arr[10]={2,-5,4,5,-15,7,-6,9,3,-10};
    vector<int>v;
    int k=3,p;
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            v.push_back(arr[i]);
            p=i;
            break;
        }
    }
    int i=1,j=k;
    while(j<10){
        if(p>=i){
            v.push_back(arr[p]);
        }
        else{
            for(int s=i;s<i+k;s++){
                if(arr[s]<0){
                    v.push_back(arr[s]);
                    p=s;
                    break;
                }
            }
        }
        i++;
        j++;
    }
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
}