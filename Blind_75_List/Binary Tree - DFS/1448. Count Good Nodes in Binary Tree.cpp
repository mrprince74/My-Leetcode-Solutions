//Problem Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/

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
    const int inf = 1e9 + 3;
    int ans = 0;
    void dfs(TreeNode* root, int max_so_far){
        if (!root) return;
        ans += (root->val >= max_so_far);
        dfs(root->left, max(max_so_far, root->val));
        dfs(root->right, max(max_so_far, root->val));
    }
    
    int goodNodes(TreeNode* root) {
        dfs(root, -inf);
        return ans;
    }
};