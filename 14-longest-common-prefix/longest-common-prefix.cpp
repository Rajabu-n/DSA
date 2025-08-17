class Solution {
public:
    string longestCommonPrefix(vector<string>& arr) {
    sort(arr.begin(),arr.end());
	string com="";
	string first=arr[0];
	int n=arr.size();
	string last=arr[n-1];
	int len=min(first.size(),last.size());
	for(int i=0;i<len;i++)
	{
		if(first[i]==last[i]) com+=first[i];
		else break;
	}
	return com;
    }
};