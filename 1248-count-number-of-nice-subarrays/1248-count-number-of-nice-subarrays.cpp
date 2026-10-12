class Solution {
private:
    int helper(vector<int>& nums, int goal){
        if(goal < 0) return 0;
        int left = 0, right = 0, count = 0, sum = 0;
        while(right < nums.size()){
            sum += (nums[right] & 1);
            while(sum > goal){
                sum = sum - (nums[left] & 1);
                left++;
            }
            count += right - left + 1;
            right++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return helper(nums, k) - helper(nums, k - 1);
    }
};

// Brute Force : Generate all the subarrays and check the number of odd numbers present in it using a counter