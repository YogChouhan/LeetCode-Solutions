class Solution {
public:
    double myPow(double x, int n) {
        long long power = n;
        double ans = 1.0;
        if(power < 0) power = power * -1;
        while(power > 0){
            if(power%2 == 1){
                ans = ans * x;
                power--;
            }
            else{
                x = x * x;
                power = power/2;
            }
        }
        if(n < 0){
            ans = (double)1 / (double)ans;
        }
        return ans;
    }
};