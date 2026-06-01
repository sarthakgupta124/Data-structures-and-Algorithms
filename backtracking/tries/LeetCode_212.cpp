#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node* childrens[26]={NULL};
    string word="";
};
class Solution {
public:
    vector<string>ans;
    vector<vector<int>>dir={{0,1},{0,-1},{1,0},{-1,0}};
    void search(Node* &root,vector<vector<char>>&board,int i,int j){
        if(root->word!=""){
            ans.push_back(root->word);
            root->word="";
        }
        for(int k=0;k<4;k++){
            int x=i+dir[k][0];
            int y=j+dir[k][1];
            if(x>=0 && x<board.size() && y>=0 && y<board[0].size() &&board[x][y]!='.' && root->childrens[board[x][y]-'a']!=NULL){
                char t=board[x][y];
                board[x][y]='.';
                search(root->childrens[t-'a'],board,x,y);
                board[x][y]=t;
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Node* root=new Node();
        // for(string word:words) root->insert(word);
        for(string word:words){
            Node* curr=root;
            for(char ch:word){
                if(curr->childrens[ch-'a']!=NULL) curr=curr->childrens[ch-'a'];
                else{
                    Node*temp=new Node();
                    curr->childrens[ch-'a']=temp;
                    curr=temp;
                }
            }
            curr->word=word;
        }

        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(root->childrens[board[i][j]-'a']!=NULL){
                    char t=board[i][j];
                    board[i][j]='.';
                    search(root->childrens[t-'a'],board,i,j);
                    board[i][j]=t;
                }
            }
        }
        return ans;
    }
};