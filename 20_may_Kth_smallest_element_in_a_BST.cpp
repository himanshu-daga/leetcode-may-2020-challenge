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
    int kthSmallest(TreeNode* root, int k) {
        // int n = numNodes(root);
        vector<int> v;
        inOrder(root, v);
        return v[k-1];
    }
    
    void inOrder(TreeNode * root, vector<int> &v){
        if(root!=nullptr){
            inOrder(root->left,v);
            v.push_back(root->val);
            inOrder(root->right,v);
        }
        return;
    }
};
