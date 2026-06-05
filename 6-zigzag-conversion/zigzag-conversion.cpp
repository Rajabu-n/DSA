class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        vector<string>value(numRows,"");
        int i=0;
        int n=s.size();
        if(numRows==1) return s;
        while(i<n)
        {
            int k=0;
            while(k<numRows && i<n)
            {
                value[k]+=s[i];
                i++;
                k++;
            }
            if(numRows>=3)
            {
               int j=numRows-2;
               while(j>0 && i<n) 
                {
                    value[j]+=s[i];
                    j--;
                    i++;
                } 
            }
        }
        for(string c:value)
        {
                result+=c;
        }
        return result;
    }
};