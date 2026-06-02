class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++)
        {
            swap(s[i],s[n-i-1]);
        }
        string ans="";
        for(int i=0;i<n;i++)
        {
            string word="";
            if(s[i]==' ')continue;
            while(i<n && s[i]!=' ')
            {
                word+=s[i];
                i++;
            }
            reverse(word.begin(),word.end());
            if(!ans.empty())ans+=" ";
            ans+=word;
        }
        return ans;
    }
};