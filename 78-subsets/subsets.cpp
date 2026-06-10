class Solution {
public:
    void findSet(int ind,vector<int>& arr,vector<vector<int>>& ans,vector<int>& ds)
    {
        if(ind==arr.size())
        {
            ans.push_back(ds);
            return;
        }
        ds.push_back(arr[ind]);
        findSet(ind+1,arr,ans,ds);
        ds.pop_back();
        findSet(ind+1,arr,ans,ds);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int>ds;
        findSet(0,nums,ans,ds);
        return ans;
    }
};