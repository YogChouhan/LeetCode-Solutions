class Solution {
private:
    bool possible(vector<int>& bloomDay, int day, int m, int k){
        int cnt=0, possible_bouquets=0;
        for(int i=0; i<bloomDay.size(); i++){
            if(bloomDay[i]<=day){
                cnt++;
            }
            else{
                possible_bouquets+=cnt/k;
                cnt=0;
            }
        }
        possible_bouquets+=cnt/k;
        if(possible_bouquets>=m){
            return true;
        }
        else{
            return false;
        }
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size(),low=INT_MAX, high=INT_MIN, mid;

        if((long long)m*k>n){return -1;}

        for(int i=0; i<n; i++){
            low=min(low, bloomDay[i]);
            high=max(high, bloomDay[i]);
        }

        while(low<=high){
            mid=low+(high-low)/2;
            if (possible(bloomDay,mid,m,k)){
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return low;
    }
};