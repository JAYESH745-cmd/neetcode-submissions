class Solution {
public:
    bool isValidBST(TreeNode* root) {
        TreeNode* curr=root;
        vector<int> ans;
        while(curr){
            if(curr->left){
                TreeNode* pred=curr->left;
                while(pred->right && pred->right!=curr){
                    pred=pred->right;
                }
                //linking
                if(!pred->right){
                    pred->right=curr;
                    curr=curr->left;
                }
                else{
                    pred->right=NULL;
                    ans.push_back(curr->val);
                    curr=curr->right;
                }
            }
            else{
                ans.push_back(curr->val);
                curr=curr->right;
            } 
        }
        for(int i=1;i<ans.size();i++){
            if(ans[i-1]>ans[i]) return false;
        }
        return true;
    }
};
