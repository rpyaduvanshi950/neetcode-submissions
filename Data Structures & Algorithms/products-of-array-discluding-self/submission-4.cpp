class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        long long product = 1;
        int zeroCount = 0;

        for (int x : nums) {
            if (x == 0)
                zeroCount++;
            else
                product *= x;
        }

        vector<int> ans(nums.size());

        for (int i = 0; i < nums.size(); i++) {

            if (zeroCount > 1) {
                ans[i] = 0;
            }
            else if (zeroCount == 1) {
                if (nums[i] == 0)
                    ans[i] = product;
                else
                    ans[i] = 0;
            }
            else {
                ans[i] = product / nums[i];
            }
        }

        return ans;
    }
};