#include <iostream>
using namespace std;
#include <unordered_map>
int main(){
    array<int, 6> a = {1,2,3,1,3,3};
    unordered_map<int, int> m;
    for(int i=0; i<a.size(); i++){
        m[a[i]]++;
    }
    for(int i=0; i<a.size(); i++){
        
    }
   
}