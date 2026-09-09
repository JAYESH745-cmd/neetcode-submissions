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
    TreeNode* build(vector<int>& preorder, vector<int>& inorder,int pre_i,int pre_j,int in_i,int in_j){
        if(pre_i>pre_j) return NULL;
        TreeNode* root=new TreeNode(preorder[pre_i]);
        int left=0,right=0;
        for(int i=in_i;i<=in_j;i++){
            if(preorder[pre_i]==inorder[i]){
                left=i-in_i;
                right=in_j-i;
                break;
            }
        }
        root->left=build(preorder,inorder,pre_i+1,pre_i+left,in_i,in_i+left-1);
        root->right=build(preorder,inorder,pre_i+left+1,pre_j,in_i+left+1,in_j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pre_i=0,pre_j=preorder.size()-1;
        int in_i=0,in_j=inorder.size()-1;
        return build(preorder,inorder,pre_i,pre_j,in_i,in_j);
    }
};
