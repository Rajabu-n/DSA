class Solution {
public:
    bool isPalindrome(const string& s,int left,int right)
    {
        while(left<right)
        {
            if(s[left]!=s[right])return false;
            left++;
            right--;
        }
        return true;

    }
    int countSubstrings(string s) {
        int n=s.size();
        int result=n;
        for(int i=0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                if(s[i]==s[j])
                {
                    if(isPalindrome(s,i,j))result++;
                }
                
            }
        }
        return result;

    }
};