class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> map;

        for (const auto& str : strs) {
            string copy = str;
            sort(copy.begin(), copy.end());
            map[copy].push_back(str);
        }
        vector<vector<string>> res;
        for (auto& [k,v] : map) {
            res.push_back(std::move(v));
        }

        return res;
    }
};
