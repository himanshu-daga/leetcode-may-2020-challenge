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
    TreeNode* insertNode(TreeNode *root, TreeNode *t){
        if(root==nullptr)
            root = t;
        else if(root->val < t->val)
            root->right = insertNode(root->right, t);
        else if(root->val > t->val)
            root->left = insertNode(root->left, t);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int l = preorder.size();
        if(l<1) 
            return nullptr;
        TreeNode *root = nullptr, *t;
        for(auto &x: preorder){
            t = new TreeNode(x);
            root = insertNode(root, t);
        }
        return root;
    }
};
