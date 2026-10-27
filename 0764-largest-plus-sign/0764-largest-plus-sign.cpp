class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> grid(n, vector<int>(n, 1));

        for (auto& mine : mines) {
            grid[mine[0]][mine[1]] = 0;
        }

        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                count = grid[i][j] ? count + 1 : 0;
                dp[i][j] = count;
            }

            count = 0;
            for (int j = n - 1; j >= 0; j--) {
                count = grid[i][j] ? count + 1 : 0;
                dp[i][j] = min(dp[i][j], count);
            }
        }

        int ans = 0;

        for (int j = 0; j < n; j++) {
            int count = 0;
            for (int i = 0; i < n; i++) {
                count = grid[i][j] ? count + 1 : 0;
                dp[i][j] = min(dp[i][j], count);
            }

            count = 0;
            for (int i = n - 1; i >= 0; i--) {
                count = grid[i][j] ? count + 1 : 0;
                dp[i][j] = min(dp[i][j], count);
                ans = max(ans, dp[i][j]);
            }
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna