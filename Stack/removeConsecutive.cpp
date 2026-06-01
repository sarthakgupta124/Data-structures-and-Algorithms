#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Stack{
public:
    vector<char>aa;
    Stack(){

    }
    void push(char k){
        aa.push_back(k);
    }
    int len(){
        return aa.size();
    }
    char top(){
        if(aa.size()==0) return '0';
        return aa[aa.size()-1];
    }
    void print(){
        for(int i=0;i<aa.size();i++){
            cout<<aa[i];
        }
    }

};
int main(){
    Stack an;
    string vs;
    getline(cin,vs);
    for(int i=0;i<vs.size();i++){
        if(an.top()!=vs[i]){
            an.push(vs[i]);
        }
    }
    an.print();
    
}