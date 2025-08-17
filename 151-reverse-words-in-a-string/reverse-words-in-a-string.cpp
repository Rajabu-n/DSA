#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string str) {
    int n=str.length();
    string ans;
    for(int i=0;i<n/2;i++)
    {
        swap(str[i],str[n-i-1]);
    }
    for(int i=0;i<n;i++)
    {
        if(str[i]==' ')continue;
        string word="";
        while(i<n && str[i]!=' ')
        {
            word+=str[i];
            i++;
        }
        reverse(word.begin(),word.end());
        if(!ans.empty()) ans+=" ";
        ans+=word;
    }
    return ans;
}

};