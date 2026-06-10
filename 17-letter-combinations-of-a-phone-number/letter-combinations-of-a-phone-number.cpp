class Solution {
public:
    void findCombination(int ind,vector<string>& ans,string& digits,string &s,string combos[])
    {
        if(ind==digits.size())
        {
            ans.push_back(s);
            return;
        }
        int digit=digits[ind]-'0';
        for(char c:combos[digit])
        {
            s.push_back(c);
            findCombination(ind+1,ans,digits,s,combos);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        string combos[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        string s;
        findCombination(0,ans,digits,s,combos);
        return ans;

    }
};