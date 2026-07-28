class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> count(26, 0);
        for (char c : s) {
            count[c - 'a']++;
        }

        string first_half = "";
        char middle_char = '\0';

        for (int i = 0; i < 26; ++i) {
            if (count[i] % 2 != 0) {
                middle_char = 'a' + i;
            }
            first_half.append(count[i] / 2, 'a' + i);
        }

        string second_half = first_half;
        reverse(second_half.begin(), second_half.end());

        if (middle_char != '\0') {
            return first_half + middle_char + second_half;
        }
        
        return first_half + second_half;
    }
};
