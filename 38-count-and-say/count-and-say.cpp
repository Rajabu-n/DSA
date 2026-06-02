class Solution {
public:
    string getNext(string s)
    {
        string ans="";
        int i=0;
        while(i<s.size())
        {
            int count=1;
            while(i+1<s.size() && s[i]==s[i+1])
            {
                count++;
                i++;
            }
            ans+=to_string(count);
            ans+=s[i];
            i++;
        }
        return ans;
    }
    string countAndSay(int n) {
        string result="1";
        for(int i=2;i<=n;i++)
        {
            result=getNext(result);
        }
        return result;
    }
};