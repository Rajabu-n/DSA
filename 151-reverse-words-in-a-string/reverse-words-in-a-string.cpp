class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
        for(int i=0;i<n;i++)
        {
            if(s[i]==' ') continue;
            string word="";
            while(i<n && s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(!ans.empty())ans+=' ';
            ans+=word;
        }
        return ans;
    }
};