class Solution {
public:
        vector<int> nse(const vector<int> &arr)
        {
            int n=arr.size();
            vector<int>nse(n);
            stack<int>st;
            for(int i=n-1;i>=0;i--)
            {
                while(!st.empty() && arr[st.top()]>=arr[i])
                {
                    st.pop();
                }
                nse[i]=st.empty()? n:st.top();
                st.push(i);  
            }
            return nse;
        }
        vector<int> pse(const vector<int> &arr)
        {
            int n=arr.size();
            vector<int>pse(n);
            stack<int>st1;
            for(int i=0;i<n;i++)
            {
                while(!st1.empty() && arr[st1.top()]>arr[i])
                {
                    st1.pop();
                }
                pse[i]= st1.empty()? -1:st1.top();
                st1.push(i);
            }
            return pse;
        }
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        vector<int>next_small=nse(arr);
        vector<int>prev_small=pse(arr);
        long long sum=0;
        int mod=1e9+7;
        for(int i=0;i<n;i++)
        {
            long long left=i-prev_small[i];
            long long right=next_small[i]-i;
           sum = (sum + arr[i] * left % mod * right % mod) % mod;
        }
        return sum;
    }
};