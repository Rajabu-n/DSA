class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>freq;
        for(char c:s)
        {
            freq[c]++;
        }
        int n=s.length();
        vector<string>bucket(n+1);
        for(auto x:freq)
        {
            bucket[x.second]+=x.first;
        }
        string ans;
        for(int i=n;i>=1;i--)
        {
            for(char x:bucket[i])
            {
                ans.append(i,x);
            }
        }
        return ans;
    }
};