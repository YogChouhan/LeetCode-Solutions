class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> hashArray(256,-1);
        int right = 0, left = 0, n = s.size(), maxlen = 0;
        while(right < n){
            if(hashArray[s[right]] != -1){
                if(hashArray[s[right]] >= left){
                    left = hashArray[s[right]] + 1;
                }
            }
            hashArray[s[right]] = right;
            maxlen = max(maxlen, right-left+1);
            right++;
        }
        return maxlen;
    }
};