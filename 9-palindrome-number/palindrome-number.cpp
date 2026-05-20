class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        int org=x;
        int revnum=0;
        while(x!=0)
        {
            if(revnum>INT_MAX /10 || revnum<INT_MIN /10) return false;
            revnum=revnum*10+x%10;
            x/=10;
        }
        if(revnum==org) return true;
        return false;
    }
};