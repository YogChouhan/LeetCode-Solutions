class Solution {
public:
    int maxDepth(string s) {
        int curr_depth=0, max_depth=0;
        for(auto it: s){
            if(it == '(') {
                curr_depth++;
                max_depth=max(max_depth,curr_depth);
            }
            else if(it == ')') curr_depth--;
        }
        return max_depth;
    }
};