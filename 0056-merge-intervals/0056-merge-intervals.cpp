class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty() || intervals.size() == 1) {
            return intervals; 
        }
    
        sort(intervals.begin(), intervals.end()); // Sort the intervals based on their start times.
        
        vector<vector<int>> mergedIntervals;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (mergedIntervals.empty() || mergedIntervals.back()[1] < intervals[i][0]) {
                mergedIntervals.push_back(intervals[i]);
            } else {
                mergedIntervals.back()[1] = max(mergedIntervals.back()[1], intervals[i][1]);
            }
        }
        
        return mergedIntervals;
    }
//Code by ~ Md Sohag Biswas
};
