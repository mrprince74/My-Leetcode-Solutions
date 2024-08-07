//Problem Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/

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
    const int inf = 1e9 +3;
    #define print(a) for (auto i : a) cout << i << " "; cout << "\n";
public:
    int bfs(TreeNode* root){
        queue<TreeNode*> q;
        vector<int> vals;
        int to_find = root->val;
        int lvl = 1;
        int best = -inf;
        int ans = -inf;
        q.push(root);
        while(q.size()){
            auto top = q.front();
            int n = q.size();
            int total = 0;
            for(int i = 0; i<n; i++){
                auto node = q.front();
                q.pop();
                total += node->val;
                if (node->right)
                    q.push(node->right);
                if (node->left)
                    q.push(node->left);
            }
            if (total > best){
                best = total;
                ans = lvl;
            }

            lvl++;
            
        }
    return ans;
    }
    int maxLevelSum(TreeNode* root) {
        int ans = bfs(root);
        return ans;
        
    }
};