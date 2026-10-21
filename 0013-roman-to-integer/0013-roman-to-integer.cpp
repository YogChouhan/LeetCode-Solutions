class Solution {
private:
    int number(char c){
        if (c == 'I') return 1;
        else if (c == 'V') return 5;
        else if (c == 'X') return 10;
        else if (c == 'L') return 50;
        else if (c == 'C') return 100;
        else if (c == 'D') return 500;
        return 1000;
    }
public:
    int romanToInt(string s) {
        int num=0;
        int prev_val=0;
        for(int n=s.size()-1; n>=0; n--){
            int curr_val = number(s[n]);
            if (curr_val<prev_val) num = num - curr_val;
            else num = num + curr_val;
            prev_val = curr_val;
        }
        return num;
    }
};