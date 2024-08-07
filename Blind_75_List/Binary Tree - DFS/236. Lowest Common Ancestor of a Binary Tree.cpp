//Problem Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
/*
     Note: This is not the optimal solution for the LCA Problem.
     There is a better solution that works in O(log(N)) using Binary Lifting, but since this solution is good enough, 
     and the optimal solution is not common in interviews. To be honest, I was satisfied with this solution and was lazy enough not to 
     implement the optimal solution :)
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    map<TreeNode*, TreeNode*> parent;
    void dfs(TreeNode* node){
        if (node->left){
            parent[node->left] = node;
            dfs(node->left);
        }
        
        if (node->right){
            parent[node->right] = node;
            dfs(node->right);
        }
    }
public:
    void get_parents(TreeNode* node, vector<TreeNode*> &ret){
         ret.push_back(node);
        if (parent[node] == node){
            return;
        }
        get_parents(parent[node], ret);
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        parent[root] = root;
        dfs(root);
        vector<TreeNode*> p_parents, q_parents;
        p_parents.push_back(p);
        q_parents.push_back(q);
        get_parents(p, p_parents);
        get_parents(q, q_parents);
        
        map<TreeNode*, bool> exist_p;
        for(auto node: p_parents)
            exist_p[node] = 1;
            
            
        for(auto node: q_parents){
            if (exist_p[node])
                return node;
        }
        
        return nullptr;
        
        
    }
};