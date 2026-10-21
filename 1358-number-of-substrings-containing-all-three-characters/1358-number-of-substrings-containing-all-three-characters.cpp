class Solution {
public:
    int numberOfSubstrings(string s) {
        // with every char there is a substring this is ending
        int lastSeen[3] = {-1, -1, -1}, countSubstrings = 0;

        for(int i = 0; i < s.size(); i++){
            lastSeen[s[i] - 'a'] = i;
            // if(lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1){ 
            //     countSubstrings = countSubstrings + (1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2])));
            // }
            // No need to check the above condition as if there were no a/b/c found then 0 would be added to the count
            countSubstrings += 1 + min({lastSeen[0], lastSeen[1], lastSeen[2]});
        }
        return countSubstrings;
    }
};

// TC: O(N)
// SC: O(3) = O(1)