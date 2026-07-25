class Solution {
    void dfs(vector<int>& nums, int target, int start, vector<int>& path, vector<vector<int>>& res) {
        if (!target) { res.push_back(path); return; }
        for (int i = start; i < nums.size(); ++i) {
            if (nums[i] > target) continue;
            path.push_back(nums[i]);
            dfs(nums, target - nums[i], i, path, res);
            path.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(candidates, target, 0, path, res);
        return res;
    }
};