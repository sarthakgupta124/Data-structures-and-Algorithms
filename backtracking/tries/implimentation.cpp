#include <bits/stdc++.h>   ///leetcode 208
using namespace std;
class Node{
public:
    char val;
    bool terminal;
    unordered_map<char,Node*>children;
    Node(char val){
        this->val=val;
        this->terminal=false;
    }
    void makeTerminal(){
        this->terminal=true;
    }
};
class Trie {
public:
    Node*root;
    Trie() {
        root =new Node('0');
    }
    
    void insert(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->children.count(word[i])){
                curr=curr->children[word[i]];
            }
            else{
                Node*temp=new Node(word[i]);
                curr->children.insert({word[i],temp});
                curr=temp;
            }
        }
        curr->makeTerminal();
        return ;
    }
    
    bool search(string word) {
        Node* curr=root;
        for(int i=0;i<word.size();i++){
            if(curr->children.count(word[i])){
                curr=curr->children[word[i]];
            }
            else{
                return false;
            }
        }
        if(curr->terminal) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        Node* curr=root;
        for(int i=0;i<prefix.size();i++){
            if(curr->children.count(prefix[i])){
                curr=curr->children[prefix[i]];
            }
            else{
                return false;
            }
        }
        return true;
    }
};
int main(){

}
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */