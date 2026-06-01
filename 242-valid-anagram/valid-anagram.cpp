class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())return false;
        int map1[256],map2[256];
        memset(map1,0,sizeof(map1));
        memset(map2,0,sizeof(map2));
        for(int i=0;i<s.size();i++)
        {
            char c1=s[i];
            char c2=t[i];

            map1[c1]++;
            map2[c2]++;
        }
        for(int i=0;i<s.size();i++)
        {
            char c1=s[i];

            if(map1[c1]!=map2[c1])return false;
        }
        return true;
    }
};