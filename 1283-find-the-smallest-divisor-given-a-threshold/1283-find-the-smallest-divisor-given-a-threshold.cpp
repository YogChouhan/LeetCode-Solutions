class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1, high=0, mid;
        long long s=0;
        for(int it:nums){
            high=max(high,it);
        }
        while(low<=high){
            mid=low+(high-low)/2;
            s=0;
            for(int it:nums){
                s+=(it + mid - 1) / mid;
            }
            if(s<=threshold){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};