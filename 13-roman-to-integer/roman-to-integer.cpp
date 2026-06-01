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
           int cur=returnValue(s[i]);
           int next=returnValue(s[i+1]);

           if(i+1<n && cur<next )
           {
                result+=next-cur;
                i++;
           }
           else
           {
            result+=cur;
           }
        }
        return result;
    }
};