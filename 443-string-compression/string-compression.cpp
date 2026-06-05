class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0;
        int index=0;
        while(i<chars.size())
        {
            char cur=chars[i];
            int count=0;
            while(i<chars.size() && chars[i]==cur)
            {
                count++;
                i++;
            }
            chars[index++]=cur;
            if(count>1)
            {
                string digit=to_string(count);
                for(char c:digit)
                {
                    chars[index++]=c;
                }
            }
        }
        return index;
    }
};