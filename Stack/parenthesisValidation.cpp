#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Stack{
public:
    vector<char> aa;
    Stack() {}
    void pop() {
        aa.pop_back();
    }
    void push(char c) {
        aa.push_back(c);
    }
    int len() {
        return (int)aa.size();
    }
    char top() {
        return aa.back();
    }
};
int main() {
    Stack an;
    bool ans = true;
    string para;
    getline(cin, para);
    for (int i = 0; i < para.size(); i++) {
        char c = para[i];
        if (c == '(' || c == '{' || c == '[') {
            an.push(c);
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (an.len() == 0) {
                ans = false;
                break;
            }
            an.pop();
        }
    }
    if (an.len() > 0) ans = false;
    cout << (ans ? "Valid" : "Invalid") << endl;
    return 0;
}