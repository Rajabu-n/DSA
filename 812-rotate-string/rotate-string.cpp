class Solution {
public:
    bool rotateString(string s, string goal) {
        int n=s.size();
        if(s.size()!=goal.size())return false;
        string doubled=s+s;
        for(int i=0;i<2*n;i++)
        {
            string rotated=doubled.substr(i,n);
            if(rotated==goal)return true;
        }
        return false;
    }
};