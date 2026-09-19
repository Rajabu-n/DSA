class Solution {
    public int subarraySum(int[] nums, int k) {
        HashMap<Integer,Integer>mpp=new HashMap<>();
        mpp.put(0,1);
        int prefixsum=0;
        int count=0;
        for(int i=0;i<nums.length;i++)
        {
            prefixsum+=nums[i];
            int remove=prefixsum-k;
            if(mpp.containsKey(remove))
            {
                count+=mpp.get(remove);
            }
            mpp.put(prefixsum,mpp.getOrDefault(prefixsum,0)+1);
        }
        return count;
    }
}