#include <iostream>
using namespace std;
#include <unordered_map>
int main(){
    //pairs class
    pair<int, int> p;
    p.first = 10;
    p.second = 20;
    cout<<p.first<<" "<<p.second<<endl;

    //unordered map is a collection of key-value pairs where each key is unique and maps to a single value.
    unordered_map<string, int> m;
    pair<string, int> p1;
    p1.first = "abc";
    p1.second = 1;
    m.insert(p1); 
    pair<string, int> p3("ghi", 3);
    m.insert(p3);
    pair<string, int> p4=make_pair("jkl", 4);
    m.insert(p4);
    m["mno"] = 5; // this is the most common way to insert key-value pairs in an unordered map
    for(pair<string, int> p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    // we can use auto keyword to avoid writing pair<string, int> every time
    for(auto p : m){
        cout<<p.first<<" "<<p.second<<endl;
    }
    cout<<m.size()<<endl;
    m.erase("abc"); // this will remove the key-value pair with key "abc" from the unordered map
    cout<<m.size()<<endl;
    return 0;
}