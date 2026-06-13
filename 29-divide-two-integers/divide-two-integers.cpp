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
            long long  power=1;
            long long sum=d;
            while(n>=2*sum)
            {
                sum*=2;
                power*=2;
            }
            n-=sum;
            ans+=power;
        }
        if(ans>INT_MAX && isPositive) return INT_MAX;;
        if(ans >INT_MAX && !isPositive) return INT_MIN;

        return isPositive? ans:-1*ans;
    }
};