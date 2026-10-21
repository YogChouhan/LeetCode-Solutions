class Solution {
private:
    void Recursive(int index ,vector<int>&temp, vector<int>&nums, vector<vector<int>>&ans, int &n){
        if(index >= n){
            ans.push_back(temp);
            return;
        }
        //include the current element
        temp.push_back(nums[index]);
        Recursive(index + 1, temp, nums, ans, n);
        //exclude the current element
        temp.pop_back();
        Recursive(index + 1, temp, nums ,ans, n);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        Recursive(0, temp, nums, ans, n);
        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> subsets(vector<int>& nums) {
//         int n = nums.size();
//         int numberOfSubsets = 1<<n;
//         vector<vector<int>> ans;

//         for (int i = 0; i <= numberOfSubsets-1; i++){
//             vector<int> temp;
//             for(int j = 0; j <= n-1; j++){
//                 if(i & (1<<j)){
//                     temp.push_back(nums[j]);
//                 }
//             }
//             ans.push_back(temp);
//         }

//         return ans;
//     }
// };