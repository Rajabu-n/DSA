class Solution {
public:
    void findCombination(int i,vector<vector<int>>& ans,vector<int>&ds,int k,int target)
    {
        if(i==10){
            if(target==0 && ds.size()==k)
            {
                ans.push_back(ds);
            }
            return;
        }
        ds.push_back(i);
        findCombination(i+1,ans,ds,k,target-i);
        ds.pop_back();
        findCombination(i+1,ans,ds,k,target);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>ds;
        findCombination(1,ans,ds,k,n);
        return ans;
    }
};