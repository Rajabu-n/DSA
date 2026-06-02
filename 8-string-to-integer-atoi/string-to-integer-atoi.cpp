class Solution {
public:
    int myAtoi(string s) {
        int i=0;
        long long ans=0;
        int sign=1;
        int n=s.size();
        while(i<n && s[i]==' ')i++;
        if(i<n && (s[i]=='-'||s[i]=='+'))
        {
            if(s[i]=='-')sign=-1;
            i++;
        }
        while(i<n && isdigit(s[i]))
        {
            ans=(ans*10)+(s[i]-'0');
            if((sign*ans)<INT_MIN)return INT_MIN;
            if((sign*ans)>INT_MAX)return INT_MAX;
            i++;

        }
        return (sign)*(ans);
    }
};