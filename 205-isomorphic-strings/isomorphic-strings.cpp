class Solution {
public:
    bool isIsomorphic(string s, string t) {
    if(s.length()!=t.length()) return false;
    int map1[256],map2[256];
    for(int i=0;i<s.length();i++)
    {
        char c1=s[i];
        char c2=t[i];
        if(map1[c1]==0 && map2[c2]==0 )
        {
            map1[c1]=c2;
            map2[c2]=c1;
        }
        else
        {
            if(map1[c1]!=c2 || map2[c2]!=c1)
            {
                return false;
            }
        }
    }
    return true;
}
        
};