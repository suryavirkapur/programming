// Anagram Groups — group strings that are anagrams of each other.
// Refactored: namespace dsa, shared test harness.
#include "dsa/dsa.hpp"
#include "dsa/test_harness.hpp"

namespace dsa {

class AnagramGrouper {
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

}  // namespace dsa

using namespace dsa;

int main() {
    TestRunner runner;
    AnagramGrouper ag;

    runner.test("example 1 — basic groups", [&] {
        vector<string> input = {"eat","tea","tan","ate","nat","bat"};
        auto result = ag.groupAnagrams(input);
        // Order of groups / elements is not specified; just verify sizes.
        ASSERT_EQ(result.size(), 3UL);
        int two = 0, three = 0;
        for (auto& g : result) {
            if (g.size() == 2UL) ++two;
            if (g.size() == 3UL) ++three;
        }
        ASSERT_EQ(two, 1);
        ASSERT_EQ(three, 1);
    });

    runner.test("empty input", [&] {
        vector<string> input = {};
        auto result = ag.groupAnagrams(input);
        ASSERT_EQ(result.size(), 0UL);
    });

    runner.test("single string", [&] {
        vector<string> input = {"hello"};
        auto result = ag.groupAnagrams(input);
        ASSERT_EQ(result.size(), 1UL);
        ASSERT_EQ(result[0].size(), 1UL);
    });

    runner.report();
    return runner.failures() > 0 ? 1 : 0;
}
