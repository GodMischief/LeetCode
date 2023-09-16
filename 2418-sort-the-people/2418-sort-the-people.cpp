class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<string> ans;
        ans.reserve(names.size());

        vector<pair<int, string>> people;

        for (int i = 0; i < names.size(); ++i)
            people.emplace_back(heights[i], names[i]);

        sort(people.rbegin(), people.rend());

        for (const auto& person : people)
            ans.emplace_back(person.second);

        return ans;
    }
};
