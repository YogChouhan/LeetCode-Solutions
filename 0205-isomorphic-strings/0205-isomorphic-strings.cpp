class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> arrS(256,-1);
        vector<int> arrT(256,-1);
        for(int i = 0; i < s.size(); i++){
            char c1 = s[i];
            char c2 = t[i];
            if(arrS[c1] != arrT[c2]){
                return false;
            }
            arrS[c1] = i;
            arrT[c2] = i;
        }
        return true;
    }
};