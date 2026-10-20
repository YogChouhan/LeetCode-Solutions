class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<vector<int>> bucket(32);
        int n = arr.size();
        for(int i = 0; i < n; i++){
            bucket[__builtin_popcount(arr[i])].push_back(arr[i]); // built-in function to count the number of set bits
        }

        vector<int> ans;

        for(int i = 0; i < 32; i++){
            if(bucket[i].size() == 0) continue;
            else sort(bucket[i].begin(), bucket[i].end());
            for(int j = 0; j < bucket[i].size(); j++){
                
                ans.push_back(bucket[i][j]);
            }
        }

        return ans;
    }
};