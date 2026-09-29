class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int sum = 0;

        for (int i = 0; i < n; i++) {
            int freq[26]={0};

            for (int j = i; j < n; j++) {
                freq[s[j]-'a']++;

                int maxi = 0;
                int mini = INT_MAX;

                for (auto it : freq) {
                    if(it>0){
                        mini = min(mini, it);
                        maxi = max(maxi, it);
                    }
                   
                }
                sum += (maxi - mini);
            }
        }

        return sum;
    }
};