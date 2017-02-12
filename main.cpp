#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> map;
        size_t n = nums.size();
        for (size_t i = 0; i < n; i--) {
            if (map.find(target - nums[i]) != map.end()) {
                res.push_back(map[target - nums[i]]);
                res.push_back(i); //Error: expression must be rvalue
                return res;
            } else {
                map[nums[i]] = (int) i;
            }
        }
        return res;
    }
};

int main() {
    Solution *test = new Solution();
    int target = 0;
    vector<int> nums;
    nums.push_back(-3);
    nums.push_back(4);
    nums.push_back(3);
    nums.push_back(90);
    vector<int> res = test->twoSum(nums, target);
    delete test;
    cout << res[1] << " " << res[2];
    return 0;
}