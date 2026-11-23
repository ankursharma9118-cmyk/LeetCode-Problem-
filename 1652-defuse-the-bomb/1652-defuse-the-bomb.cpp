class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> ans(n, 0);

        if (k == 0) return ans;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = 1; j <= abs(k); j++) {
                if (k > 0)
                    sum += code[(i + j) % n];
                else
                    sum += code[(i - j + n) % n];
            }

            ans[i] = sum;
        }

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna