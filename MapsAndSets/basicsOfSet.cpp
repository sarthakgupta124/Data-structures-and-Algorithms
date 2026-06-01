#include <iostream>
using namespace std;
#include <unordered_set>
int main(){
    unordered_set<int> s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    cout<<s.size()<<endl;
    for(int ele : s){
        cout<<ele<<" ";
    }
    cout<<endl;
    //s.find() returns an iterator to the element if it is present in the set, else it returns an iterator to the end of the set
    int target = 3;
    if(s.find(target) != s.end()){
        cout<<target<<" is present in the set"<<endl;
    }
    else{
        cout<<target<<" is not present in the set"<<endl;
    }
}