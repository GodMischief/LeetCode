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
/*Recursive Approach*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;
        
        //level-order traversal
        function<void(TreeNode*, int)> traverse = [&](TreeNode* node, int depth) {
            if (!node) return;
            if (depth == result.size()) {
                result.push_back(vector<int>());
            }
            
            traverse(node->left, depth + 1);
            traverse(node->right, depth + 1);
            result[depth].push_back(node->val); // Store values at their respective levels
        };
        
        traverse(root, 0);
        reverse(result.begin(), result.end()); // Reverse the result to get bottom-up order
        return result;
    }
};


