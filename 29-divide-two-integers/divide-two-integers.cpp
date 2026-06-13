class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        bool isPositive=true;

        if(dividend>=0 && divisor<0 ) isPositive=false;
        if(dividend<0 && divisor>0 ) isPositive=false;

        long long n=dividend;
        long long d=divisor;

        n=abs(n);
        d=abs(d);

        long long ans=0;
        while(n>=d)
        {
            long long count=0;
            while(n>=d<<(count+1))
            {
                count++;
            }
            n-=d<<count;
            ans+=(1<<count);
        }
        if(ans>INT_MAX && isPositive) return INT_MAX;;
        if(ans >INT_MAX && !isPositive) return INT_MIN;

        return isPositive? ans:-1*ans;
    }
};