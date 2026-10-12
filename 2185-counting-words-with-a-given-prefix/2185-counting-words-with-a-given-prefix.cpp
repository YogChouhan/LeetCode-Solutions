class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int count = 0;
        for(int i = 0; i < words.size(); i++){
            bool flag = true;
            for(int j = 0; j < pref.size(); j++){
                if(pref[j] != words[i][j]){
                    flag = false;
                    break;
                }
            }
            if (flag) count++;
        }
        return count;
    }
};