class Solution {
public:
    int MOD=1e9+7;
    long long power(long long base,long long n)
    {
        long long ans=1;
        while(n>0)
        {
            if(n%2)
            {
                ans=(ans*base)%MOD;
                n=n-1;
            }
            else
            {
                base=(base*base)%MOD;
                n=n/2;
            }
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        long long evenpos=(n+1)/2;
        long long oddpos=n/2;
        return (power(5,evenpos)* power(4,oddpos))%MOD;
    }
};