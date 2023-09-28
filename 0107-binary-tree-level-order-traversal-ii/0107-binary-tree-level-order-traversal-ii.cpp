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
/*Iterative Approach Using Queue*/
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> result; 
        
        if (!root) return result; 
        
        queue<TreeNode*> q; 
        q.push(root); 
        
        while (!q.empty()) {
            int levelSize = q.size(); // Get the number of nodes at the current level.
            vector<int> levelValues;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front(); // Get the front node from the queue.
                q.pop(); 
                levelValues.push_back(node->val);
                
                if (node->left) q.push(node->left); // Push the left child if it exists.
                if (node->right) q.push(node->right); // Push the right child if it exists.
            }
            
            result.push_back(levelValues);
        }
        
        reverse(result.begin(), result.end()); 
        return result; 
        //Code by ~ Md Sohag Biswas
    }
};


