//Problem Link: https://leetcode.com/problems/longest-zigzag-path-in-a-binary-tree/

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
    int dfs(TreeNode* node, bool was_left, int len){
        if (!node) return len;
        if (was_left){
            int a = dfs(node->right, 0, len + 1);
            int b = dfs(node->left, 1, 0);
            return max(a,b);
        }
        else{
            int a = dfs(node->left, 1, len + 1);
            int b = dfs(node->right, 0, 0);
            return max(a,b);
        }
        
    }
    
    int longestZigZag(TreeNode* root) {
        int a = dfs(root->left, true, 0);
        int b = dfs(root->right, false, 0);
        return max(a,b);
    }
};