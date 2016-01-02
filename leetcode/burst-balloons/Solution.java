public class Solution {
    private int[] nums;
    public int maxCoins(int[] nums) {
        this.nums = nums;
        int n = nums.length + 2;
        int[][] dp = new int[n][n];
        for (int k = 2; k < n; ++k) {
            for (int l = 0; l < n - k; ++l) {
                int r = l + k;
                for (int m = l + 1; m < r; ++m) {
                    dp[l][r] = Math.max(dp[l][r], get(l) * get(m) * get(r) + dp[l][m] + dp[m][r]);
                }
            }
        }
        return dp[0][n - 1];
    }
    private int get(int i) {
        if (i == 0 || i == nums.length + 1) {
            return 1;
        }
        return nums[i - 1];
    }
}
