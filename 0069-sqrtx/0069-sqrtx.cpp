class Solution {
public:
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        int low = 1, high = x/2;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(mid > (x / mid)) high = mid - 1; // if mid was long long then simply use mid * mid > x
            else low = mid + 1;
        }
        return high;
    }
};