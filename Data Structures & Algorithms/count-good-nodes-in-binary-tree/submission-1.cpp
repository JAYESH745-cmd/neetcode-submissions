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
    void good(TreeNode* root,int& count,int temp){
        if(!root) return;
        if(root->val>=temp){
            count++;
            temp=root->val; 
        }
        good(root->left,count,temp);
        good(root->right,count,temp);
    }
    int goodNodes(TreeNode* root) {
        int count=0;
        int temp= root->val;
        good(root,count,temp);
        return count;
    }
};