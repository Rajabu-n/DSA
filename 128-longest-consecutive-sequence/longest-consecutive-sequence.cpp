class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int n=nums.size();
        if(n==0) return 0;
        for(auto i:nums)
        {
            st.insert(i);
        }
        int count;
        int longest=INT_MIN;
        for(auto it:st)
        {
            if(st.find(it-1)==st.end())
            {
                int x=it;
                count=1;
                while(st.find(x+1)!=st.end())
                {
                    x++;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};