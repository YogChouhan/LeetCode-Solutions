class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if(strs.empty()) return result;
        for(int i = 0; i < strs[0].size(); i++){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != c || strs[j].size() == i){
                    return result;
                }
            }
            result += c;
        }
        return result;
    }
};