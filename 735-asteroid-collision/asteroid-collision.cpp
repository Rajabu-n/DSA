class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        int n=asteroids.size();
        vector<int>result;
        for(int i=0;i<n;i++)
        {
            if(st.empty())
            {
                st.push(asteroids[i]);
                continue;
            }
            bool found=false;
            while(!st.empty() && asteroids[i]<0 && st.top()>0)
            {
               
                if(st.top()< abs(asteroids[i]))
                {
                    st.pop();
                    continue;

                }
                else if(st.top()==abs(asteroids[i]))
                {
                    st.pop();
                }
                found=true;
                break;
            }
            if(!found)
            {
                    st.push(asteroids[i]);
             }
           
        }
         while(!st.empty())
            {
                result.push_back(st.top());
                st.pop();
            }
        reverse(result.begin(),result.end());
        return result;
    }
};