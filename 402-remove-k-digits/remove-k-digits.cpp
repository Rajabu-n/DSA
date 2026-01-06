class Solution {
public:
    string removeKdigits(string num, int k) {
     stack<char>st;
     string result;
     for(char c:num)
     {
        while(!st.empty() && k>0 && st.top()>c)
        {
            st.pop();
            k--;
        }
        st.push(c);
     }
     while(k>0 && !st.empty())
     {
        st.pop();
        k--;
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