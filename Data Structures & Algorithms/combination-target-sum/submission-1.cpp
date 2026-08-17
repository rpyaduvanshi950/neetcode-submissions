class Solution {
    void dfs(vector<int>& nums, int target,
             vector<int>& res,
             vector<vector<int>>& ans,
             int i) {

        if (target == 0) {
            ans.push_back(res);
            return;
        }

        if (i >= nums.size() || target < 0)
            return;

        // Take nums[i]
        if (nums[i] <= target) {
            res.push_back(nums[i]);

            // DON'T move i
            dfs(nums, target - nums[i], res, ans, i);

            res.pop_back();
        }

        // Don't take nums[i]
        dfs(nums, target, res, ans, i + 1);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        vector<int> res;

        dfs(nums, target, res, ans, 0);

        return ans;
    }
};