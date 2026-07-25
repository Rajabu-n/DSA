class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            char c=s[i];
            if(!ans.empty() && ans.back()==c)
            {
                ans.pop_back();
            }
            else
            {
                ans.push_back(c);
            }
        }
        return ans;
    }
};