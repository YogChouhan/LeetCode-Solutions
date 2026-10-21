class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int actual_sum=0;
        int pred_sum=nums.size()*(nums.size()+1)/2;
        for (int i=0; i<nums.size(); i++){
            actual_sum = actual_sum + nums[i];
        }
        return pred_sum-actual_sum;
    }
};