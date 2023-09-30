class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals.size() == 1) {
            return intervals; 
        }
    
        sort(intervals.begin(), intervals.end()); // Sort the intervals based on their start times.
        
        vector<vector<int>> mergedIntervals;
        vector<int> currentInterval = intervals[0];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (currentInterval[1] >= intervals[i][0]) {
                
                currentInterval[1] = max(currentInterval[1], intervals[i][1]); // Merge the overlapping intervals by updating the end time.
            } else {
                mergedIntervals.push_back(currentInterval);
                currentInterval = intervals[i];
            }
        }
        mergedIntervals.push_back(currentInterval);
        
        return mergedIntervals;
    }
//Code by ~ Md Sohag Biswas
};
