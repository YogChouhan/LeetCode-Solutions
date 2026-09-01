class Solution {
public:
    int firstUniqChar(string s) {
        int seen[26]={0};
        for(int i = 0; i < s.length(); i++){
            seen[s[i]-'a']++;
        }
        for(int i = 0; i < s.length(); i++){
            if(seen[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};