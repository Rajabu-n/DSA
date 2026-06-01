class Solution {
public:
    string frequencySort(string s) {
        int count[256]={0};
        for(int i=0;i<s.size();i++)
        {
            count[s[i]]++;
        }
        string result="";
        while(true)
        {
            int maxfreq=0;
            char maxchar;
            for(int i=0;i<256;i++)
            {
                if(count[i]>maxfreq)
                {
                    maxchar=(char)i;
                    maxfreq=count[i];
                }
            }
            if(maxfreq==0)break;
            for(int i=0;i<maxfreq;i++)
            {
                result+=maxchar;
            }
            count[maxchar]=0;
        }
        return result;
    }
};