class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rows; // {sum, index}

        // Iterate through the matrix to calculate the row sums and store them with their indices
        for (int i = 0; i < mat.size(); ++i)
            rows.emplace_back(accumulate(mat[i].begin(), mat[i].end(), 0), i);

        // Sort the rows vector, so the weakest rows (based on sum) come first
        sort(rows.begin(), rows.end());

        vector<int> ans;

        // Extract the indices of the k weakest rows
        for (int i = 0; i < k; ++i)
            ans.push_back(rows[i].second);

        return ans;
    }
};
