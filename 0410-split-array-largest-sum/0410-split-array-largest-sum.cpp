class Solution {
private:
    int findSumSplit(vector<int>& nums, int mid){
        int sumEle=0, cnt=1;
        for(int i=0; i<nums.size(); i++){
            if(sumEle + nums[i]<= mid){
                sumEle+=nums[i];
            }
            else{
                cnt++;
                sumEle=nums[i];
            }
        }
        return cnt;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low=0, high=0, mid;
        for(auto i: nums){
            if(low<i){
                low=i;
            }
            high+=i;
        }
        while(low<=high){
            mid=low+(high-low)/2;
            if(findSumSplit(nums, mid)>k){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
        return low;
    }
};