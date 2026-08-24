class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lb=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int up=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lb==nums.size() || nums[lb]!=target ){
            return{-1,-1};
        }
        else{
            return{lb, up-1};
        }
    }
};