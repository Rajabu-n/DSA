class Solution {
public:
    int myAtoi(string s) {
      int digit,i=0;
	long ans=0;
	int sign=1;
	int n=s.length();
		while(i<n && s[i]==' ')
		{
		    i++;
		}
		if(i<n && (s[i]=='-'|| s[i]=='+'))
		{
		    if(s[i]=='-') sign=-1;
		    i++;
		}
		while(i<n &&isdigit(s[i]))
		{
		    digit=s[i]-'0';
		    if(ans>(INT_MAX-digit)/10)
		    {
		        return sign==1?INT_MAX:INT_MIN;
		    }
		    ans=ans*10+digit;
		    i++;
		}
		return sign*ans;
    }
};