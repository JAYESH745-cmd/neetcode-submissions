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
    void pre(TreeNode* root,vector<int>&arr){
        if(!root) {
            arr.push_back(-1);
            return;
        }
        arr.push_back(root->val);
        pre(root->left,arr);
        pre(root->right,arr);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int> p1;
        vector<int> p2;
        pre(p,p1);
        pre(q,p2);
        if(p1==p2) return true;
        return false;
    }
};
