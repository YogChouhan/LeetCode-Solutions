class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxLen = 0, left = 0, right = 0, zeroes = 0;

        while(right < nums.size()){
            if(nums[right] == 0) zeroes++;

            if(zeroes > k) {
                if(nums[left] == 0) zeroes--;
                left++;
            }

            if(zeroes <= k){
                maxLen = max(maxLen, right - left + 1);
            }

            right++;
        }
        return maxLen;
    }
};

// TC: O(N), SC: O(1)

// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         int maxLen = 0, len = 0, left = 0, right = 0, zeroes = 0;

//         while(right < nums.size()){

//             if(nums[right] == 0) zeroes++;

//             while(zeroes > k){
//                 if(nums[left] == 0) zeroes--;
//                 left++;
//             }

//             if(zeroes <= k){
//                 len = right - left + 1;
//                 maxLen = max(maxLen, len);
//             }

//             right++;
//         }

//         return maxLen;
//     }
// };

// TC: O(2N), SC: O(1)