class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        string result="";
        stack<char>st;
        for(char c:num)
        {
            while(!st.empty() && st.top()>c && k>0)
            {
                st.pop();
                k--;
            }
            st.push(c);
        }
        while(k>0 && !st.empty())
        {
            k--;
            st.pop();
        } 
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(result.begin(),result.end());
        int i=0;
        while(i<result.size() && result[i]=='0') i++;
        result=result.substr(i);
        if(result.size()==0) return "0";
        else return result;
    }
};