class Solution {
private:
    static const long long MOD = 1000000007;
    long long findPower(long long base, long long power){
        long long ans = 1;
        while(power > 0){
            if((power&1) == 0){
                base = (base * base) % MOD;
                power = power/2;
            }
            else{
                ans = (ans * base) % MOD;
                power--;
            }
        }
        return ans;
    }
    
public:
    int countGoodNumbers(long long n) {
        long long cnt_even = (n+1)/2;
        long long cnt_prime = n/2;

        long long evenWays = findPower(5, cnt_even);
        long long oddWays = findPower(4, cnt_prime);

        long long answer = (evenWays * oddWays) % MOD;
        return answer;
    }
};