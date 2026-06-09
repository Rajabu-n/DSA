class Solution {
public:
    void solve(int open,int close,string cur,int n,vector<string>& result)
    {
        if(cur.size()==2*n)
        {
            result.push_back(cur);
            return;
        }
        if(open<n)
        {
            solve(open+1,close,cur+"(",n,result);
        }
        if(close<open)
        {
            solve(open,close+1,cur+")",n,result);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve(0,0,"",n,result);
        return result;
    }
};