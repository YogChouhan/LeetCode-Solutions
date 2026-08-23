class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> hashMap;
        int cnt=0,prefixSum=0;
        hashMap[0]=1;
        for(int i: nums){
            prefixSum+=i;
            cnt+=hashMap[prefixSum-k];
            hashMap[prefixSum]+=1;
        }
        return cnt;
    }
};