class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int> hashMap;
        hashMap[nums[0]]=1;
        for(int i=1; i<nums.size(); i++){
            if(hashMap.find(nums[i])!=hashMap.end()){
                return nums[i];
            }
            hashMap[nums[i]]+=1;
        }
        return -1;
    }
};