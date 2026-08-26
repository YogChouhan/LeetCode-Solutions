class Solution {
public:
    bool isAnagram(string s, string t) {
        int len1=s.size(), len2= t.size();
        if (len1!=len2) return false;

        int freq_alphabets[26]={0};

        for(int i=0; i<len1; i++){
            freq_alphabets[s[i]-'a']++;
        }
        for(int j=0; j<len2; j++){
            freq_alphabets[t[j]-'a']--;
        }
        for(int k=1; k<26; k++){
            if(freq_alphabets[k]!=0) return false;
        }
        return true;
    }
};