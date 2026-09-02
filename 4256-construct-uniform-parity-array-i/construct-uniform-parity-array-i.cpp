class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int length = nums1.size();

        if (length <= 1) {
            return true;
        }

        int counter = 0;
        for (int i; i < length; ++i) {
            if (nums1[i] % 2 != 0) {
                counter++;
            }
        }

        if (counter == 1) {
            return false;
        }

        return true;
    }
};