class Solution {
public:
    string largestOddNumber(string num) {
        int j=num.size()-1;
        while(j>=0){
            if((num[j]-'0')%2!=0){
                break;
            }
            j--;
        }
        string ans=num.substr(0, j+1);
        return ans;
    }
};