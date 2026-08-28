class Solution {
public:
    string lexPalindromicPermutation(string s, string target) { 
        int n = s.length();
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        int odd_count = 0;
        int odd_idx = -1;
        for (int i = 0; i < 26; i++) {
            if (count[i] % 2 != 0) {
                odd_count++;
                odd_idx = i;
            }
        }
        if (odd_count > 1) return "";

        vector<int> half_count(26, 0);
        for (int i = 0; i < 26; i++) {
            half_count[i] = count[i] / 2;
        }
        char mid_char = (odd_idx != -1) ? (char)('a' + odd_idx) : '\0';

        string best_res = "";
        int half_len = n / 2;

        for (int len = half_len; len >= 0; len--) {
            string prefix = target.substr(0, len);
            
            vector<int> current_pool = half_count;
            bool prefix_possible = true;
            for (char c : prefix) {
                if (--current_pool[c - 'a'] < 0) {
                    prefix_possible = false;
                    break;
                }
            }
            if (!prefix_possible) continue;

            int start_char = 0;
            if (len < half_len) {
                start_char = target[len] - 'a' + 1; 
            } else {
                string constructed_half = prefix;
                string full = constructed_half;
                if (mid_char != '\0') full += mid_char;
                reverse(constructed_half.begin(), constructed_half.end());
                full += constructed_half;
                
                if (full > target) {
                    if (best_res == "" || full < best_res) best_res = full;
                }
                continue;
            }

            for (int c = start_char; c < 26; c++) {
                if (current_pool[c] > 0) {
                    vector<int> remaining_pool = current_pool;
                    remaining_pool[c]--;

                    string suffix = "";
                    for (int i = 0; i < 26; i++) {
                        suffix += string(remaining_pool[i], (char)('a' + i));
                    }

                    string first_half = prefix + (char)('a' + c) + suffix;
                    string full_palindrome = first_half;
                    if (mid_char != '\0') full_palindrome += mid_char;
                    reverse(first_half.begin(), first_half.end());
                    full_palindrome += first_half;

                    if (full_palindrome > target) {
                        if (best_res == "" || full_palindrome < best_res) {
                            best_res = full_palindrome;
                        }
                        break;
                    }
                }
            }
        }

        return best_res;
    }
};