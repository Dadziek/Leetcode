class Solution {
public:
    string toLowerCase(string s) {
        for(int i = 0; i < s.length(); i++){
            if (65 <= s[i] && s[i] <= 90){
                s[i] += 32;
            }
        }
        return s;
    }
};