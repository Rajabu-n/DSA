class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int>freq;
        vector<int>res;
        for(int x:nums)
        {
            freq[x]++;
        }
        for(int i=1;i<=nums.size();i++)
        {
                if(freq[i]==0) res.push_back(i);
        }
        return res;
    }
};