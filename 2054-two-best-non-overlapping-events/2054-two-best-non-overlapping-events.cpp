struct Event {
    int time, value;
    bool isStart;
    Event(int t, int v, bool s) : time(t), value(v), isStart(s) {}
};

class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
        int ans = 0, maxValue = 0;
        vector<Event> evts;

        for (const auto& event : events) {
            int start = event[0], end = event[1], value = event[2];
            evts.emplace_back(start, value, true);
            evts.emplace_back(end + 1, value, false);
        }

        sort(evts.begin(), evts.end(), [](const Event& a, const Event& b) {
            return a.time == b.time ? a.isStart < b.isStart : a.time < b.time;
        });

        for (const auto& [_, value, isStart] : evts) {
            if (isStart) ans = max(ans, value + maxValue);
            else maxValue = max(maxValue, value);
        }

        return ans;
    }
};
