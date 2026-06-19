class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>mp;
        int start = 0;
        int left=0,right=0;
        for(char x:t)
        {
            mp[x]++;
        }
        int m=t.size();
        int n=s.size();
        int count=0;
        int minlen=INT_MAX;
        while(right<n)
        {
            if(mp[s[right]]>0) 
            {
                count++;
            }
            mp[s[right]]--;
            while(count==m)
            {
                if(right-left+1<minlen)
                {
                    minlen=right-left+1;
                    start=left;
                }
                mp[s[left]]++;
                if(mp[s[left]]>0) count--;
                left++;
            }
            right++; 
        }
        if(minlen == INT_MAX)
    return "";

return s.substr(start,minlen);
    }
};