class Solution {
private:
    int reqdDays(vector<int>& weights, int capacity){
        int days=1, load=0;
        for(int i=0; i<weights.size(); i++){
            if(load + weights[i]>capacity){
                days=days+1;
                load=weights[i];
            }
            else{
                load+=weights[i];
            }
        }
        return days;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=0,high=0,mid;
        for(int it: weights){
            low=max(low,it);
            high+=it;
        }
        while(low<=high){
            mid=low+(high-low)/2;
            if(reqdDays(weights, mid)<=days){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
    return low;
    }
};