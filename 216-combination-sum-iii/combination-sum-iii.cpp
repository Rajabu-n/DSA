class Solution {
public:
    void findCombination(int ind,vector<int>& arr,vector<vector<int>>& ans,vector<int>&ds,int k,int target)
    {
        if(ind==arr.size()){
            if(target==0 && ds.size()==k)
            {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(arr[ind]);
        findCombination(ind+1,arr,ans,ds,k,target-arr[ind]);
        ds.pop_back();
        findCombination(ind+1,arr,ans,ds,k,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>ds;
        vector<int>arr;
        for(int i=1;i<=9;i++)
        {
            arr.push_back(i);
        }
        findCombination(0,arr,ans,ds,k,n);
        return ans;
    }
};