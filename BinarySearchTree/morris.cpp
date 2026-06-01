#include <bits/stdc++.h>
using namespace std;
// leetcode 114. Flatten Binary Tree to Linked List
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
class Solution {
public:
    void flatten(TreeNode* root) {
        //morris approach
        TreeNode* curr=root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode* r=curr->right;
                curr->right=curr->left;
                TreeNode* pre=curr->left;
                while(pre->right!=NULL) pre=pre->right;
                pre->right=r;
                curr=curr->left;
            }
            else curr=curr->right;
        }
        while(root!=NULL){
            root->left=NULL;
            root=root->right;
        }
        return;
    }
};