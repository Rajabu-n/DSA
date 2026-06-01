class Solution {
public:
    int returnValue(char c)
    {
        switch(c){
        
        case 'I': return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D': return 500;
        case 'M':return 1000;
        }
        return 0;
    }
    int romanToInt(string s) {
        int n=s.length();
        int result=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='I'&& s[i+1]=='V')
            {
                result+=4;
                i++;
                continue;
            }
            if(s[i]=='I'&& s[i+1]=='X')
            {
                result+=9;
                i++;
                continue;
            }
            if(s[i]=='X'&& s[i+1]=='L')
            {
                result+=40;
                i++;
                continue;
            }
            if(s[i]=='X'&& s[i+1]=='C')
            {
                result+=90;
                i++;
                continue;
            }
            if(s[i]=='C'&& s[i+1]=='D')
            {
                result+=400;
                i++;
                continue;
            }
            if(s[i]=='C'&& s[i+1]=='M')
            {
                result+=900;
                i++;
                continue;
            }
            result+=returnValue(s[i]);
        }
        return result;
    }
};