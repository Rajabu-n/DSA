class Solution {
public:
    vector<int>buildlps(const string& s)
    {
        int n=s.size();
        vector<int>lps(n,0);
        
        int len=0;
        int i=1;
        while(i<n)
        {
            if(s[len]==s[i])
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
                else{
                   len=lps[len-1];
                }
            }
        }
        return lps;

    }
    string longestPrefix(string s) {
        
        vector<int>lps=buildlps(s);
        int len=lps[s.size()-1];
        return s.substr(0,len);
    }
};