class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        partitionhelper(0,ans,path,s);
        return ans;
    }
    void partitionhelper(int index,vector<vector<string>>& ans,vector<string>&path,string s)
    {
        if(index==s.length())
        {
            ans.push_back(path);
            return;
        }
        for(int i=index;i<s.length();i++)
        {
            if(ispalindrome(index,i,s))
            {
                path.push_back(s.substr(index,i-index+1));
                partitionhelper(i+1,ans,path,s);
                path.pop_back();
            }
        }
    }
    bool ispalindrome(int start,int end,string s)
    {
        while(start<end)
        {
            if(s[start]!=s[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};