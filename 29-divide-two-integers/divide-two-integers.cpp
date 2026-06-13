class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor==1) return dividend;
        if(divisor==dividend) return 1;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX;

        bool isPositive=true;
        if(dividend<0 && divisor>0) isPositive=false;
        if(dividend>=0 && divisor<0) isPositive=false;
        
        long long n=dividend;
        long long d=divisor;

        n=abs(n);
        d=abs(d);

        long long sum=0,ans=0;
        while(sum+d<=n)
        {
            ans++;
            sum+=d;
        }
        if(ans>INT_MAX && isPositive) return INT_MAX;
        if(ans>INT_MAX && !isPositive) return INT_MIN;

        return isPositive?ans:-1*ans;

    }
};