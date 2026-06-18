class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0;
        int right=0;
        int maxlen=0;
        int n=s.size();
        vector<int>hash(256,0);
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