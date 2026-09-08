class Solution {
public:
    bool exists(TreeNode* root,TreeNode* p){
        if(!root) return false;
        if(root->val==p->val) return true;
        return exists(root->left,p) || exists(root->right,p);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val==p->val || root->val==q->val) return root;
        else if((exists(root->left,p) && exists(root->right,q)) || (exists(root->left,q) && exists(root->right,p))) return root;
    TreeNode* left=lowestCommonAncestor(root->left,p,q);
    if(left) return left;
    TreeNode* right=lowestCommonAncestor(root->right,p,q);
    if(right) return right;
    return NULL;
    }
};
