//Problem Link: https://leetcode.com/problems/binary-tree-right-side-view

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
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        vector<int> ans;
        while(!q.empty()){
            if (q.back())
                ans.push_back(q.back()->val);
            int n = q.size();
            for(int i = 0; i < n; i++){
                auto node = q.front();
                q.pop();
                if (node && node->left)
                    q.push(node->left);
                if (node && node->right)
                    q.push(node->right);
                
            }
        }
        return ans;
    }
};