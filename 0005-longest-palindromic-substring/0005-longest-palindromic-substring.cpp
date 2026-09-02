class Solution {
private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        return right - left - 1; 
    }
public:
    string longestPalindrome(string s) {
        if (s.length() <= 1) return s;
        
        int start = 0;
        int max_len = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // for odd-length palindromes (center is one character)
            int len1 = expandAroundCenter(s, i, i);
            
            // for even-length palindromes (center is between characters)
            int len2 = expandAroundCenter(s, i, i + 1);
            int current_max = max(len1, len2);
            
            if (current_max > max_len) {
                max_len = current_max;
                start = i - (current_max - 1) / 2; 
            }
        }
        return s.substr(start, max_len);
    }
};