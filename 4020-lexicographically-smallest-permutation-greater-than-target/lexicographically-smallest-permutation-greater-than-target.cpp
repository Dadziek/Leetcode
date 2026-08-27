class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string result = "";
        
        auto dfs = [&](auto& self, int idx, bool is_greater) -> bool {
            if (idx == n) {
                return is_greater;
            }

            if (is_greater) {
                for (int i = 0; i < 26; ++i) {
                    if (count[i] > 0) {
                        count[i]--;
                        result.push_back('a' + i);
                        if (self(self, idx + 1, true)) {
                            return true;
                        }
                        result.pop_back();
                        count[i]++;
                    }
                }
                return false;
            }

            int target_char = target[idx] - 'a';

            if (count[target_char] > 0) {
                count[target_char]--;
                result.push_back(target[idx]);
                if (self(self, idx + 1, false)) {
                    return true;
                }
                result.pop_back();
                count[target_char]++;
            }

            for (int i = target_char + 1; i < 26; ++i) {
                if (count[i] > 0) {
                    count[i]--;
                    result.push_back('a' + i);
                    if (self(self, idx + 1, true)) {
                        return true;
                    }
                    result.pop_back();
                    count[i]++;
                }
            }

            return false;
        };

        if (dfs(dfs, 0, false)) {
            return result;
        }
        return "";
    }
};
