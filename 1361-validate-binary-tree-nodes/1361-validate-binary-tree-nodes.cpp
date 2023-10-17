class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<int> inDegree(n, 0);

        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                inDegree[leftChild[i]]++;
                if (inDegree[leftChild[i]] > 1) {
                    return false;
                }
            }

            if (rightChild[i] != -1) {
                inDegree[rightChild[i]]++;
                if (inDegree[rightChild[i]] > 1) {
                    return false;
                }
            }
        }

        int rootCount = 0;
        int rootIndex = -1;

        for (int i = 0; i < n; i++) {
            if (inDegree[i] == 0) {
                rootCount++;
                if (rootCount > 1) {
                    return false;
                }
                rootIndex = i;
            }
        }

        if (rootCount == 0 || rootCount > 1) {
            return false;
        }

        // Perform a depth-first search from the root node to check if it forms a valid tree.
        vector<bool> visited(n, false);
        stack<int> dfsStack;
        dfsStack.push(rootIndex);

        while (!dfsStack.empty()) {
            int node = dfsStack.top();
            dfsStack.pop();

            if (visited[node]) {
                return false; // Cycle detected.
            }

            visited[node] = true;

            if (leftChild[node] != -1) {
                dfsStack.push(leftChild[node]);
            }

            if (rightChild[node] != -1) {
                dfsStack.push(rightChild[node]);
            }
        }

        for (bool v : visited) {
            if (!v) {
                return false; // Some nodes are not part of the tree.
            }
        }

        return true;
    }
};
