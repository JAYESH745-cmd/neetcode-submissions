/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    void good(TreeNode* root,int temp,int &count){
        if(!root) return;
        if(root->val>=temp){
            count++;
        }
        temp=max(temp,root->val);
        good(root->left,temp,count);
        good(root->right,temp,count);
    }
    int goodNodes(TreeNode* root) {
        int temp=root->val;
        int count=0;
        good(root,temp,count);
        return count;
    }
};
