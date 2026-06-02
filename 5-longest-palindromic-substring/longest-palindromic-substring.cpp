class Solution {
public:
    
    string longestPalindrome(string s) {
        int start=0;
        int maxlen=0;
        int n=s.size();
        int len;
        //even length
        for(int i=0;i<n;i++)
        {
            int left=i;
            int right=i+1;
            while(left>=0 && right<n && s[left]==s[right])
            {
                len=right-left+1;
                if(len>maxlen)
                {
                    maxlen=len;
                    start=left;
                }
                left--;
                right++;
            }

            //odd length
            left=i;
            right=i;
            while(left>=0 && right<n && s[left]==s[right])
            {
                    len=right-left+1;
                    if(len>maxlen)
                    {
                        maxlen=len;
                        start=left;
                    }
                    left--;
                    right++;
            }
        }
        return s.substr(start,maxlen);
    }
};