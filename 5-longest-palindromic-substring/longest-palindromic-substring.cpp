class Solution {
public:
    bool isPalindrome(const string &s,int start,int end)
    {
        while(start<end)
        {
            if(s[start]!=s[end])return false;
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        string result="";
        int maxcount=0;
        int n=s.size();
        int count;
        for(int i=0;i<s.size();i++)
        {
            
            for(int j=n-1;j>=i;j--)
            {
                if(s[i]==s[j])
                {
                    bool found=isPalindrome(s,i,j);
                    if(found)
                    {
                        count=j-i+1;
                        if(count>maxcount){
                            maxcount=count;
                            result = s.substr(i, count);
                        }
                        break;

                    }
                }
            }
        }
        return result;
    }
};