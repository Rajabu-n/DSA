class Solution {
public:
    int helper(const string& s,int i,long long num,int sign)
    {
        if(!isdigit(s[i]) || i>s.size()) return (int)sign*num;
        num=num*10+s[i]-'0';
        if(sign*num>INT_MAX) return INT_MAX;
        if(sign*num<INT_MIN) return INT_MIN;
        return  helper(s,i+1,num,sign);
        
    }
    int myAtoi(string s) {
        int n=s.size();
        int i=0;
        int sign=1;
        while(i<n && s[i]==' ')i++;
        if(i<n && (s[i]=='+'||s[i]=='-') )
        {
            if(s[i]=='-')sign=-1;
            i++;
        }
        return helper(s,i,0,sign);
    }
};