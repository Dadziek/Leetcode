class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int target = k;
        
        while (numSet.count(target)) {
            target += k;
        }

        return target;
    }
};