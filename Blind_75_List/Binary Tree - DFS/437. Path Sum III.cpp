//Problem Link: https://leetcode.com/problems/path-sum-iii/

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
    int dfs(TreeNode* node, long long need){
        if (!node)
            return 0;
        int me = (need == node->val);
        me+= dfs(node->left, (long long) need - node->val);
        me+= dfs(node->right, (long long) need - node->val);
        return me;
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root)
            return 0;
        int ans = 0;
        vector<TreeNode*> st{root};
        while(!st.empty()){
            auto node = st.back();
            st.pop_back();
            ans+= dfs(node, (long long) targetSum);
            if (node->left)
                st.push_back(node->left);
            if (node->right)
                st.push_back(node->right);
        }
        return ans;
    }
};