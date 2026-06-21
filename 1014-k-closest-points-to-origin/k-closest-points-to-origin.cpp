class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<int, vector<pair<int,int>>> mp;
        for (auto& p : points) {
            int x = p[0], y = p[1];
            int distSq = x*x + y*y;
            mp[distSq].push_back({x, y});
        }

        vector<vector<int>> ans;
        for (auto& [dist, pts] : mp) {
            for (auto& pr : pts) {
                if ((int)ans.size() == k) return ans;
                ans.push_back({pr.first, pr.second});
            }
        }
        return ans;
    }
};