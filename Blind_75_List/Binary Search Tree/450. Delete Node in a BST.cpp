//Problem Link: https://leetcode.com/problems/delete-node-in-a-bst/

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
    TreeNode* build(const vector<int>& arr){
        if (arr.empty())
            return nullptr;
        int l = 0, r = arr.size() - 1, mid = (l + r) / 2;
        TreeNode* me = new TreeNode(arr[mid]);
        if (mid - 1 >= 0)
            me->left = build(vector<int>(arr.begin(), arr.begin() + mid));
        if (mid + 1 <= arr.size())
            me->right = build(vector<int>(arr.begin() + mid + 1, arr.end()));
        return me;
    }
    void dfs(TreeNode* node, vector<int>& arr, int bad){
        if (!node)
            return;
        if (node->val != bad)
            arr.push_back(node->val);
        dfs(node->left, arr, bad);
        dfs(node->right, arr, bad);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        vector<int> arr;
        dfs(root, arr, key);
        sort(arr.begin(), arr.end()); // to make sure only
        return build(arr);
    }
};