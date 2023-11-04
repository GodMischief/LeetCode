//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
public:
    bool is_Possible(vector<vector<int>>& grid)
    {
        int n = grid.size();
        if (n == 0) return false;
        
        pair<int, int> source, destination;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    source = {i, j};
                } else if (grid[i][j] == 2) {
                    destination = {i, j};
                }
            }
        }
        
        function<bool(int, int)> dfs = [&](int x, int y) -> bool {
            if (x < 0 || x >= n || y < 0 || y >= n || grid[x][y] == 0) {
                return false;
            }
            if (x == destination.first && y == destination.second) {
                return true;
            }
            int originalValue = grid[x][y];
            grid[x][y] = 0;
            bool found = dfs(x + 1, y) || dfs(x - 1, y) || dfs(x, y + 1) || dfs(x, y - 1);
            grid[x][y] = originalValue;
            return found;
        };
        
        return dfs(source.first, source.second);
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>grid(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		bool ans = obj.is_Possible(grid);
		cout << ((ans) ? "1\n" : "0\n");
	}
	return 0;
}
// } Driver Code Ends