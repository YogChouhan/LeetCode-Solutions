class Solution {
private:
    void backTrack(string current_string, int openBrackets, int closeBrackets, vector<string> &result, int &n){
        if(current_string.size()==2*n){
            result.push_back(current_string);
            return;
        }

        if(openBrackets < n){
            current_string.push_back('(');
            backTrack(current_string, openBrackets + 1, closeBrackets, result, n);
            current_string.pop_back();
        }

        if(closeBrackets < openBrackets){
            current_string.push_back(')');
            backTrack(current_string, openBrackets, closeBrackets + 1, result, n);
            current_string.pop_back();
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        backTrack("", 0 , 0, result, n);
        return result;
    }
};