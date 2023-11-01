/*
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
    vector<int> findMode(TreeNode* root) {
        vector<int> result;
        int current = 0;  // Initialize with any value
        int count = 0;
        int maxCount = 0;

        // In-order traversal using Morris Traversal
        TreeNode* current_node = root;
        while (current_node) {
            if (!current_node->left) {
                // No left child, process the current node
                if (current_node->val == current) {
                    count++;
                } else {
                    current = current_node->val;
                    count = 1;
                }
                if (count > maxCount) {
                    maxCount = count;
                    result.clear();
                    result.push_back(current);
                } else if (count == maxCount) {
                    result.push_back(current);
                }
                current_node = current_node->right;
            } else {
                // Find the predecessor of the current node
                TreeNode* predecessor = current_node->left;
                while (predecessor->right && predecessor->right != current_node) {
                    predecessor = predecessor->right;
                }

                if (predecessor->right) {
                    // Revert the threaded link
                    predecessor->right = nullptr;
                    if (current_node->val == current) {
                        count++;
                    } else {
                        current = current_node->val;
                        count = 1;
                    }
                    if (count > maxCount) {
                        maxCount = count;
                        result.clear();
                        result.push_back(current);
                    } else if (count == maxCount) {
                        result.push_back(current);
                    }
                    current_node = current_node->right;
                } else {
                    // Thread the link to the predecessor
                    predecessor->right = current_node;
                    current_node = current_node->left;
                }
            }
        }

        return result;
    }
};
