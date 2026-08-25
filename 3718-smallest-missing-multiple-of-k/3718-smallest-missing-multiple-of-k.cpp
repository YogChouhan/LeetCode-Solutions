class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int i=1;
        unordered_set<int> st(nums.begin(),nums.end());
        while(st.contains(k*i)){
            i+=1;
        }
        return k*i;
    }
};