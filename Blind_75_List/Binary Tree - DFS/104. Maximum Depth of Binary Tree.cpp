//Problem Link: 104. Maximum Depth of Binary Tree

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
    // int depth(TreeNode* root){
    //     if (!root) return 0;
    //     return max(depth(root->left) + 1, depth(root->right) + 1);
    // }
    
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        return max(maxDepth(root->left) + 1, maxDepth(root->right) + 1);
    }
};