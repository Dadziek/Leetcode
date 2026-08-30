class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2){
            return n;
        }

        int min_val = nums[0];
        int max_val = nums[0];
        int min_idx = 0;
        int max_idx = 0;

        for (int k = 1; k < n; ++k) {
            if (nums[k] < min_val) {
                min_val = nums[k];
                min_idx = k;
            }
            if (nums[k] > max_val) {
                max_val = nums[k];
                max_idx = k;
            }
        }

        int i = min(min_idx, max_idx);
        int j = max(min_idx, max_idx);

        int both_front = j + 1;
        int both_back = n - i;
        int from_both_sides = (i + 1) + (n - j);

        return min({both_front, both_back, from_both_sides});
    }
};