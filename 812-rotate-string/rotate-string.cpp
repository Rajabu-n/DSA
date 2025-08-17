class Solution {
public:
    bool rotateString(string s, string goal) {
        	char word;
	int n=s.length();
	for(int i=0;i<n;i++)
	{
		char word=s[0];
		for(int j=1;j<n;j++)
		{
			s[j-1]=s[j];
		}
		s[n-1]=word;
		if(s==goal) return true;
	}
	return false;
        
    }
};