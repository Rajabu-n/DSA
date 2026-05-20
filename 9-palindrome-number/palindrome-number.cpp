class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || x%10==0 && x!=0) return false;
        int revhalf=0;
        while(x>revhalf)
        {
            revhalf=revhalf*10+x%10;
            x/=10;
        }
        if ( x==revhalf || x==revhalf/10) return true;
        return false;
    }
};