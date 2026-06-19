class Solution {
public:
    int characterReplacement(string s, int k) {
        int left=0;
        int right=0;
        int n=s.size();
        int maxlen=0;
        int maxfreq=0;
        int changes;
        vector<int>hash(26,0);
        while(right<n)
        {
            hash[s[right]-'A']++;
            if(hash[s[right]-'A']>maxfreq) maxfreq=hash[s[right]-'A'];
            changes=(right-left+1)-maxfreq;
            if(changes<=k)
            {
                maxlen=max(maxlen,right-left+1);
            }
            while(changes>k)
            {
                hash[s[left]-'A']--;
                left++;
                changes = (right - left + 1) - maxfreq;
            }
            right++;
        }
        return maxlen;
    }
};