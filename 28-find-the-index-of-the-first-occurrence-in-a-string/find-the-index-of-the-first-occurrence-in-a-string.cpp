class Solution {
public:
    vector<int>buildlps(const string& pattern)
    {
        int n=pattern.size();
        vector<int>lps(n,0);
        
        int len=0;
        int i=1;
        while(i<n)
        {
            if(pattern[len]==pattern[i])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len==0)
                {
                    lps[i]=0;
                    i++;
                }
                else
                {
                    len=lps[len-1];
                }
            }
        }
        return lps;
    }
    int strStr(string haystack, string needle) {
       vector<int>lps=buildlps(needle);
       int i=0;
       int j=0;
       while(i<haystack.size())
       {
            if(haystack[i]==needle[j])
            {
                i++;
                j++;
            }
            if(j==needle.size())
            {
                return i-j;
            }
            else if(i<haystack.size() && haystack[i]!=needle[j])
            {
                if(j==0)
                {
                    i++;
                }
                else{
                    j=lps[j-1];
                }
            }
       }
       return -1;

    }
};