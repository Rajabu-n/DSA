class Solution {
public:
    int maxProfit(vector<int>& prices) {
    int max_element=0;
    int min=INT_MAX;
    for(int i=0;i<prices.size();i++)
    {
        if(prices[i]<min) min=prices[i];
        else max_element=max(max_element,prices[i]-min);
    }

    return max_element;
    }
};