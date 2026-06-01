class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size())return false;
        for(int i=0;i<s.size();i++)
        {
            char word=s[0];
            for(int j=1;j<s.size();j++)
            {
                s[j-1]=s[j];
            }
            s[n-1]=word;
            if(s==goal)return true;
        }
        return false;
    }
};