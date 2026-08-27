class Solution {
public:
    string removeOuterParentheses(string s) {
        int cnt=0;
        string result="";
        result.reserve(s.length()); //pre-allocation of memory so that the result gets the memory size used by the string s
        for(auto &it: s){
            if(it=='('){
                cnt++;
                if(cnt>1) result+=it;
            }
            else{
                cnt--;
                if(cnt>0) result+=it;
            }
        }
        return result;
    }
};