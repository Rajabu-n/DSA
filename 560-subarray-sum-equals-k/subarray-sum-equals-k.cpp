class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
            unordered_map<int,int> prefixsumcount;
            prefixsumcount[0]=1;
            int prefixsum=0;
            int count=0;
            for(int i=0;i<nums.size();i++)
            {
                prefixsum+=nums[i];
                int remove=prefixsum-k;
                if(prefixsumcount.find(remove)!=prefixsumcount.end())
                {
                    count+=prefixsumcount[remove];
                }
                prefixsumcount[prefixsum]++;
            }
            return count;
    }
};