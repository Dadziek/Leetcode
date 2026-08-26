class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        vector<int> ones;
        
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == '1') {
                ones.push_back(i);
            }
        }

        if (ones.size() < k) {
            return "";
        }
        
        int min_len = INT_MAX;
        string result = "";

        for (int i = 0; i <= ones.size() - k; ++i) {
            int start = ones[i];
            int end = ones[i + k - 1];
            int current_len = end - start + 1;
            
            string candidate = s.substr(start, current_len);

            if (current_len < min_len) {
                min_len = current_len;
                result = candidate;
            } else if (current_len == min_len) {
                if (candidate < result) {
                    result = candidate;
                }
            }
        }
        
        return result;
    }
};