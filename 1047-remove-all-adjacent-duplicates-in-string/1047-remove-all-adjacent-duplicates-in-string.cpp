class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for (auto letter: s){
            if(!ans.empty() && ans.back()==letter){
                ans.pop_back();
            }
            else{
                ans.push_back(letter);
            }
        }
        return ans;
    }
};