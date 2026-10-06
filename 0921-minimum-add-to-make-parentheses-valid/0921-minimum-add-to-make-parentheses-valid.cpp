class Solution {
public:
    int minAddToMakeValid(string s) {
        int opening_needed = 0, closing_needed = 0;
        for(char c : s){
            if(c == '('){
                opening_needed++;
            }
            else{
                if(opening_needed > 0){
                    opening_needed--;
                }
                else{
                    closing_needed++;
                }
            }
        }
        return opening_needed + closing_needed;        
    }
};