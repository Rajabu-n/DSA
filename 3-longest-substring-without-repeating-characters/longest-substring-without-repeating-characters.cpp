class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int left=0;
        int right=0;
        int maxlen=0;
        vector<int>hash(260,0);
        while(right<n)
        {
            hash[s[right]]++;
            while(hash[s[right]]>1)
            {
                hash[s[left]]--;
                left++;
            }
            maxlen=max(maxlen,right-left+1);
            right++;
        }
        return maxlen;
    }
};