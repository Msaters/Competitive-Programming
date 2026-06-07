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

const int max_v = 1e5 + 7;
int G[max_v][2];
bool isChild[max_v];

class Solution {
private:
    TreeNode* dfs_build_Tree(int v) {
        if(v == 0) return nullptr;
        if(G[v][0] == 0 && G[v][1] == 0) return new TreeNode(v);
        return new TreeNode(v, dfs_build_Tree(G[v][0]), dfs_build_Tree(G[v][1]));
    }

public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        vector<int> values;
        for(auto desc : descriptions) {
            int curr = desc[0], child = desc[1], pos = desc[2];
            values.push_back(curr);
            values.push_back(child);
            G[curr][1 - pos] = child; 
            isChild[child] = true;
        }

        int root;
        // find root
        for(int v : values) {
            if(!isChild[v]) root = v;
        }

        TreeNode* rootNode = dfs_build_Tree(root);

        // clear 
         for(int v : values) {
            G[v][0] = 0;
            G[v][1] = 0;
            isChild[v] = false;
        }

        return rootNode;
    }
};