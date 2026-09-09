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

class Codec {
public:
    void code(TreeNode* root,string& s){
        if(!root) {
            s+="N.";
            return;
        }
        s+=to_string(root->val)+'.';
        code(root->left,s);
        code(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s="";
        if(!root) return "N.";
        code(root,s);
        return s;
    }
     TreeNode* decode(string& data,int& i){
        if(i>=data.size()) return NULL;
        int j=i;
        while(data[j]!='.') j++;
        string tok=data.substr(i,j-i);
        
        if(data[i]=='N'){
            i=j+1;
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(tok));
        i=j+1;
        root->left=decode(data,i);
        root->right=decode(data,i);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data[0]=='N') return NULL;
        int i=0;
        return decode(data,i);
    }
};
