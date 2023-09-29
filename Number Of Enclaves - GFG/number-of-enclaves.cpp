//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
public:
    int numberOfEnclaves(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        // Helper function to perform DFS
        function<void(int, int)> dfs = [&](int x, int y) {
            if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == 0) {
                return;
            }
            grid[x][y] = 0; // Mark the cell as visited
            dfs(x - 1, y);
            dfs(x + 1, y);
            dfs(x, y - 1);
            dfs(x, y + 1);
        };

        // Traverse the boundary and mark connected land cells
        for (int i = 0; i < rows; ++i) {
            dfs(i, 0);
            dfs(i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            dfs(0, j);
            dfs(rows - 1, j);
        }

        // Count the remaining land cells
        int count = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    count++;
                }
            }
        }

        return count;
    }
};




//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends